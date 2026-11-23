#include "Server.hpp"

Channel *Server::memberChannel(Client &c, const std::string &name) {
    Channels::iterator it = channels.find(lowerName(name));
    if (it == channels.end()) {
        reply(c, "403", name + " :No such channel");
        return NULL;
    }
    if (!it->second.members.count(c.fd)) {
        reply(c, "442", it->second.name + " :You're not on that channel");
        return NULL;
    }
    return &it->second;
}

bool Server::requireOp(Client &c, const Channel &ch) {
    Members::const_iterator member = ch.members.find(c.fd);
    if (member != ch.members.end() && member->second)
        return true;
    reply(c, "482", ch.name + " :You're not a channel operator");
    return false;
}

void Server::names(Client &c, const Channel &ch) {
    std::string batch;
    for (Members::const_iterator it = ch.members.begin(); it != ch.members.end(); ++it) {
        if (batch.size() > 350) {
            reply(c, "353", "= " + ch.name + " :" + batch);
            batch.clear();
        }
        if (!batch.empty())
            batch += " ";
        if (it->second)
            batch += "@";
        batch += clients.find(it->first)->second.nick;
    }
    if (!batch.empty())
        reply(c, "353", "= " + ch.name + " :" + batch);
    reply(c, "366", ch.name + " :End of NAMES list");
}

void Server::who(Client &c, const std::string &name) {
    Channels::iterator it = channels.find(lowerName(name));
    if (it != channels.end() && it->second.members.count(c.fd)) {
        const Channel &ch = it->second;
        for (Members::const_iterator m = ch.members.begin(); m != ch.members.end(); ++m) {
            const Client &user = clients.find(m->first)->second;
            std::string flags = m->second ? "H@" : "H";
            reply(c, "352", ch.name + " " + user.user + " " + user.host +
                  " irc.local " + user.nick + " " + flags + " :0 " + user.realName);
        }
    }
    reply(c, "315", name + " :End of WHO list");
}

void Server::join(Client &c, const Words &w) {
    if (!need(c, w, 1))
        return;
    Words rooms = commaList(w[1]);
    Words keys;
    if (w.size() > 2)
        keys = commaList(w[2]);
    for (std::size_t i = 0; i < rooms.size(); ++i) {
        std::string key;
        if (i < keys.size())
            key = keys[i];
        joinOne(c, rooms[i], key);
    }
}

void Server::joinOne(Client &c, const std::string &name, const std::string &key) {
    if (name.size() < 2 || name.size() > 50 || name[0] != '#' ||
        name.find_first_of(" ,:\a\t") != std::string::npos) {
        reply(c, "403", name + " :Invalid channel name");
        return;
    }
    std::string index = lowerName(name);
    Channels::iterator it = channels.find(index);
    if (it == channels.end())
        it = channels.insert(std::make_pair(index, Channel(name))).first;
    Channel &ch = it->second;
    if (ch.members.count(c.fd))
        return;
    if (ch.inviteOnly && !ch.invited.count(c.fd)) {
        reply(c, "473", ch.name + " :Cannot join channel (+i)");
        return;
    }
    if (!ch.key.empty() && key != ch.key) {
        reply(c, "475", ch.name + " :Cannot join channel (+k)");
        return;
    }
    if (ch.limit && ch.members.size() >= static_cast<std::size_t>(ch.limit)) {
        reply(c, "471", ch.name + " :Cannot join channel (+l)");
        return;
    }
    bool first = ch.members.empty();
    ch.members.insert(std::make_pair(c.fd, first));
    ch.invited.erase(c.fd);
    toChannel(ch, c.prefix() + " JOIN " + ch.name, -1);
    if (!ch.topic.empty())
        reply(c, "332", ch.name + " :" + ch.topic);
    names(c, ch);
}

void Server::leave(Channel &ch, int fd) {
    ch.members.erase(fd);
    if (ch.members.empty())
        channels.erase(lowerName(ch.name));
}

void Server::part(Client &c, const Words &w) {
    if (!need(c, w, 1))
        return;
    Words rooms = commaList(w[1]);
    for (std::size_t i = 0; i < rooms.size(); ++i) {
        Channel *ch = memberChannel(c, rooms[i]);
        if (ch) {
            std::string reason = w.size() > 2 ? w[2] : c.nick;
            toChannel(*ch, c.prefix() + " PART " + ch->name + " :" + reason, -1);
            leave(*ch, c.fd);
        }
    }
}

void Server::topic(Client &c, const Words &w) {
    if (!need(c, w, 1))
        return;
    Channel *ch = memberChannel(c, w[1]);
    if (!ch)
        return;
    if (w.size() == 2) {
        if (ch->topic.empty())
            reply(c, "331", ch->name + " :No topic is set");
        else
            reply(c, "332", ch->name + " :" + ch->topic);
        return;
    }
    if (ch->topicLocked && !requireOp(c, *ch))
        return;
    ch->topic = w[2].substr(0, fitBytes(w[2], 0, 300));
    toChannel(*ch, c.prefix() + " TOPIC " + ch->name + " :" + ch->topic, -1);
}

void Server::invite(Client &c, const Words &w) {
    if (!need(c, w, 2))
        return;
    Channel *ch = memberChannel(c, w[2]);
    if (!ch || !requireOp(c, *ch))
        return;
    Client *guest = findNick(w[1]);
    if (!guest || !guest->registered)
        reply(c, "401", w[1] + " :No such nick");
    else if (ch->members.count(guest->fd))
        reply(c, "443", guest->nick + " " + ch->name + " :is already on channel");
    else {
        ch->invited.insert(guest->fd);
        reply(c, "341", guest->nick + " " + ch->name);
        queue(*guest, c.prefix() + " INVITE " + guest->nick + " :" + ch->name);
    }
}

void Server::kick(Client &c, const Words &w) {
    if (!need(c, w, 2))
        return;
    Channel *ch = memberChannel(c, w[1]);
    if (!ch || !requireOp(c, *ch))
        return;
    Client *target = findNick(w[2]);
    if (!target || !target->registered)
        reply(c, "401", w[2] + " :No such nick");
    else if (!ch->members.count(target->fd))
        reply(c, "441", target->nick + " " + ch->name + " :They aren't on that channel");
    else {
        std::string reason = w.size() > 3 ? w[3] : c.nick;
        toChannel(*ch, c.prefix() + " KICK " + ch->name + " " + target->nick + " :" + reason, -1);
        leave(*ch, target->fd);
    }
}
