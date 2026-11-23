#include "Server.hpp"
#include <climits>
#include <sstream>

void Server::showModes(Client &c, const Channel &ch) {
    std::string flags = "+";
    std::ostringstream values;
    if (ch.inviteOnly)
        flags += "i";
    if (ch.topicLocked)
        flags += "t";
    if (!ch.key.empty()) {
        flags += "k";
        values << " " << ch.key;
    }
    if (ch.limit) {
        flags += "l";
        values << " " << ch.limit;
    }
    reply(c, "324", ch.name + " " + flags + values.str());
}

static bool needsValue(char flag, bool adding) {
    return flag == 'o' || (adding && (flag == 'k' || flag == 'l'));
}

// With "-ko Bob", Bob belongs to o. With "-ko oldkey Bob", skip oldkey.
static std::size_t requiredAfter(const std::string &flags, std::size_t start, bool adding) {
    std::size_t count = 0;
    for (std::size_t i = start; i < flags.size(); ++i) {
        if (flags[i] == '+' || flags[i] == '-')
            adding = flags[i] == '+';
        else if (needsValue(flags[i], adding))
            ++count;
    }
    return count;
}

bool Server::changeMode(Client &c, Channel &ch, char flag, bool adding,
                        std::string &value) {
    if (flag == 'i')
        ch.inviteOnly = adding;
    else if (flag == 't')
        ch.topicLocked = adding;
    else if (flag == 'k') {
        if (adding && (value.empty() || value.size() > 64 ||
                       value.find_first_of(" ,:\t") != std::string::npos)) {
            reply(c, "696", ch.name + " k * :Invalid channel key");
            return false;
        }
        if (adding)
            ch.key = value;
        else {
            ch.key.clear();
            value = "*";
        }
    } else if (flag == 'l') {
        int limit = adding ? positiveNumber(value, INT_MAX) : 0;
        if (adding && !limit) {
            reply(c, "696", ch.name + " l * :Invalid channel limit");
            return false;
        }
        ch.limit = limit;
    } else if (flag == 'o') {
        Client *target = findNick(value);
        if (!target || !target->registered) {
            reply(c, "401", value + " :No such nick");
            return false;
        }
        Members::iterator member = ch.members.find(target->fd);
        if (member == ch.members.end()) {
            reply(c, "441", value + " " + ch.name + " :They aren't on that channel");
            return false;
        }
        member->second = adding;
        value = target->nick;
    } else {
        reply(c, "472", std::string(1, flag) + " :Unknown mode character");
        return false;
    }
    return true;
}

void Server::mode(Client &c, const Words &w) {
    if (!need(c, w, 1))
        return;
    if (lowerName(w[1]) == lowerName(c.nick)) {
        if (w.size() == 2)
            reply(c, "221", "+");
        else
            reply(c, "501", ":User mode flag not supported");
        return;
    }
    Channel *ch = memberChannel(c, w[1]);
    if (!ch)
        return;
    if (w.size() == 2) {
        showModes(c, *ch);
        return;
    }
    if (!requireOp(c, *ch))
        return;
    bool adding = true;
    std::size_t next = 3;
    const std::string &flags = w[2];
    for (std::size_t i = 0; i < flags.size(); ++i) {
        char flag = flags[i];
        if (flag == '+' || flag == '-') {
            adding = flag == '+';
            continue;
        }
        std::string value;
        if (needsValue(flag, adding)) {
            if (next == w.size()) {
                reply(c, "461", "MODE :Missing mode parameter");
                return;
            }
            value = w[next++];
        } else if (flag == 'k' && w.size() - next > requiredAfter(flags, i + 1, adding))
            ++next;
        if (changeMode(c, *ch, flag, adding, value)) {
            std::string line = c.prefix() + " MODE " + ch->name + " ";
            line += adding ? '+' : '-';
            line += flag;
            if (!value.empty())
                line += " " + value;
            toChannel(*ch, line, -1);
        }
    }
}
