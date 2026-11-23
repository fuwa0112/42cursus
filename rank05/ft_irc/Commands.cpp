#include "Server.hpp"
#include <cctype>

std::string lowerName(std::string name) {
    for (std::size_t i = 0; i < name.size(); ++i) {
        if (name[i] >= 'A' && name[i] <= 'Z')
            name[i] += 'a' - 'A';
    }
    return name;
}

Words commaList(const std::string &text) {
    Words result;
    std::size_t start = 0;
    std::size_t comma = text.find(',');
    while (comma != std::string::npos) {
        result.push_back(text.substr(start, comma - start));
        start = comma + 1;
        comma = text.find(',', start);
    }
    result.push_back(text.substr(start));
    return result;
}

static Words parseLine(const std::string &line) {
    Words words;
    std::size_t p = line.find_first_not_of(' ');
    if (p == std::string::npos || line[p] == ':')
        return words;
    while (p != std::string::npos) {
        if (line[p] == ':') {
            words.push_back(line.substr(p + 1));
            break;
        }
        std::size_t end = line.find(' ', p);
        if (end == std::string::npos) {
            words.push_back(line.substr(p));
            break;
        }
        words.push_back(line.substr(p, end - p));
        p = line.find_first_not_of(' ', end);
    }
    for (std::size_t i = 0; i < words[0].size(); ++i)
        words[0][i] = std::toupper(static_cast<unsigned char>(words[0][i]));
    return words;
}

bool Server::need(Client &c, const Words &w, std::size_t count) {
    if (w.size() > count)
        return true;
    reply(c, "461", w[0] + " :Not enough parameters");
    return false;
}

Client *Server::findNick(const std::string &name) {
    const std::string search = lowerName(name);
    for (Clients::iterator it = clients.begin(); it != clients.end(); ++it) {
        Client &c = it->second;
        if (!c.nick.empty() && lowerName(c.nick) == search)
            return &c;
    }
    return NULL;
}

static bool validNick(const std::string &name) {
    if (name.empty() || name.size() > 30)
        return false;
    const std::string specials = "[]\\`_^{|}";
    for (std::size_t i = 0; i < name.size(); ++i) {
        char ch = name[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
            specials.find(ch) != std::string::npos)
            continue;
        if (i == 0 || ((ch < '0' || ch > '9') && ch != '-'))
            return false;
    }
    return true;
}

void Server::nick(Client &c, const std::string &newNick) {
    if (!validNick(newNick)) {
        reply(c, "432", newNick + " :Erroneous nickname");
        return;
    }
    Client *other = findNick(newNick);
    if (other && other != &c) {
        reply(c, "433", newNick + " :Nickname is already in use");
        return;
    }
    if (c.registered && c.nick != newNick)
        toPeers(c, c.prefix() + " NICK :" + newNick, true);
    c.nick = newNick;
}

void Server::welcome(Client &c) {
    if (c.registered || c.negotiating || c.nick.empty() || c.user.empty())
        return;
    if (!c.hasPass) {
        reply(c, "464", ":Password required");
        return;
    }
    c.registered = true;
    reply(c, "001", ":Welcome to ft_irc, " + c.nick);
    reply(c, "002", ":Your host is irc.local, running version 1.0");
    reply(c, "003", ":This server was created at startup");
    reply(c, "004", "irc.local 1.0 - itkol");
    reply(c, "005", "CHANTYPES=# CASEMAPPING=ascii PREFIX=(o)@ CHANMODES=,k,l,it NICKLEN=30 TOPICLEN=300 :are supported by this server");
    reply(c, "375", ":- irc.local Message of the day -");
    reply(c, "372", ":- Welcome to the ft_irc server");
    reply(c, "376", ":End of MOTD");
}

void Server::cap(Client &c, const Words &w) {
    if (!need(c, w, 1))
        return;
    std::string target = c.nick.empty() ? "*" : c.nick;
    std::string sub = lowerName(w[1]);
    if (sub == "ls") {
        c.negotiating = !c.registered;
        queue(c, ":irc.local CAP " + target + " LS :");
    } else if (sub == "end") {
        c.negotiating = false;
        welcome(c);
    } else if (sub == "list")
        queue(c, ":irc.local CAP " + target + " LIST :");
    else if (sub == "req" && need(c, w, 2)) {
        c.negotiating = !c.registered;
        queue(c, ":irc.local CAP " + target + " NAK :" + w[2]);
    }
}

void Server::registerCommand(Client &c, const Words &w) {
    if (w[0] == "NICK") {
        if (w.size() < 2 || w[1].empty()) {
            reply(c, "431", ":No nickname given");
            return;
        }
        nick(c, w[1]);
    } else if (c.registered) {
        reply(c, "462", ":You may not reregister");
        return;
    } else if (w[0] == "PASS") {
        if (!need(c, w, 1))
            return;
        if (w[1] != password) {
            reply(c, "464", ":Password incorrect");
            c.closing = true;
            return;
        }
        c.hasPass = true;
    } else if (w[0] == "USER") {
        if (!need(c, w, 4))
            return;
        if (w[1].empty() || w[1].size() > 32 ||
            w[1].find_first_of(" !@:\t") != std::string::npos) {
            reply(c, "461", "USER :Invalid username");
            return;
        }
        c.user = w[1];
        c.realName = w[4];
    }
    welcome(c);
}

void Server::privmsg(Client &c, const Words &w) {
    if (w.size() < 2 || w[1].empty()) {
        reply(c, "411", ":No recipient given");
        return;
    }
    if (w.size() < 3 || w[2].empty()) {
        reply(c, "412", ":No text to send");
        return;
    }
    Words targets = commaList(w[1]);
    for (std::size_t i = 0; i < targets.size(); ++i)
        deliverMessage(c, targets[i], w[2]);
}

void Server::deliverMessage(Client &c, const std::string &target, const std::string &text) {
    Channel *room = NULL;
    Client *dest = NULL;
    std::string header = c.prefix() + " PRIVMSG ";
    if (!target.empty() && target[0] == '#') {
        Channels::iterator it = channels.find(lowerName(target));
        if (it == channels.end()) {
            reply(c, "403", target + " :No such channel");
            return;
        }
        room = &it->second;
        if (!room->members.count(c.fd)) {
            reply(c, "404", target + " :Cannot send to channel");
            return;
        }
        header += room->name;
    } else {
        dest = findNick(target);
        if (!dest || !dest->registered) {
            reply(c, "401", target + " :No such nick");
            return;
        }
        header += dest->nick;
    }
    header += " :";
    // Adding nick!user@host can make a valid incoming line too long to relay in one piece.
    for (std::size_t start = 0; start < text.size();) {
        std::size_t count = fitBytes(text, start, MaxLine - header.size());
        std::string line = header + text.substr(start, count);
        if (room)
            toChannel(*room, line, c.fd);
        else
            queue(*dest, line);
        start += count;
    }
}

void Server::dispatch(Client &c, const std::string &line) {
    Words w = parseLine(line);
    if (w.empty())
        return;
    const std::string &cmd = w[0];
    if (cmd == "CAP")
        cap(c, w);
    else if (cmd == "PASS" || cmd == "NICK" || cmd == "USER")
        registerCommand(c, w);
    else if (cmd == "PING") {
        if (need(c, w, 1))
            queue(c, ":irc.local PONG irc.local :" + w[1]);
    } else if (cmd == "QUIT") {
        if (w.size() > 1)
            c.quitReason = w[1];
        c.closing = true;
    } else if (!c.registered)
        reply(c, "451", ":You have not registered");
    else if (cmd == "JOIN")
        join(c, w);
    else if (cmd == "PART")
        part(c, w);
    else if (cmd == "PRIVMSG")
        privmsg(c, w);
    else if (cmd == "TOPIC")
        topic(c, w);
    else if (cmd == "INVITE")
        invite(c, w);
    else if (cmd == "KICK")
        kick(c, w);
    else if (cmd == "MODE")
        mode(c, w);
    else if (cmd == "NAMES") {
        if (!need(c, w, 1))
            return;
        Channel *ch = memberChannel(c, w[1]);
        if (ch)
            names(c, *ch);
    } else if (cmd == "WHO") {
        if (need(c, w, 1))
            who(c, w[1]);
    } else if (cmd != "PONG")
        reply(c, "421", cmd + " :Unknown command");
}
