#include "Server.hpp"
#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <new>
#include <netinet/in.h>
#include <poll.h>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>

Client::Client(int socketFd, const std::string &address)
    : fd(socketFd), host(address), quitReason("Connection closed"),
      hasPass(false), registered(false), negotiating(false), closing(false), dead(false) {}

std::string Client::prefix() const {
    return ":" + nick + "!" + user + "@" + host;
}

Channel::Channel(const std::string &channelName)
    : name(channelName), inviteOnly(false), topicLocked(true), limit(0) {}

Server::Server(const std::string &pass) : listener(-1), password(pass) {}

Server::~Server() {
    for (Clients::iterator it = clients.begin(); it != clients.end(); ++it)
        close(it->first);
    if (listener >= 0)
        close(listener);
}

static bool nonBlocking(int fd) {
    return fcntl(fd, F_SETFL, O_NONBLOCK) != -1;
}

void Server::listenOn(int port) {
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0 || !nonBlocking(listener))
        throw std::runtime_error("cannot open a non-blocking TCP socket");
    int yes = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
        throw std::runtime_error("setsockopt failed");
    sockaddr_in address;
    std::memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);
    if (bind(listener, reinterpret_cast<sockaddr *>(&address), sizeof(address)) < 0)
        throw std::runtime_error("bind failed (check port and permissions)");
    if (listen(listener, MaxClients) < 0)
        throw std::runtime_error("listen failed");
}

void Server::acceptOne() {
    sockaddr_in address;
    socklen_t length = sizeof(address);
    int fd = accept(listener, reinterpret_cast<sockaddr *>(&address), &length);
    if (fd < 0)
        return;
    if (clients.size() >= MaxClients || !nonBlocking(fd)) {
        close(fd);
        return;
    }
    try {
        clients.insert(std::make_pair(fd, Client(fd, inet_ntoa(address.sin_addr))));
    } catch (const std::bad_alloc &) {
        close(fd);
    }
}

void Server::run(int port, const volatile std::sig_atomic_t &running) {
    listenOn(port);
    std::cout << "ircserv listening on 0.0.0.0:" << port << std::endl;
    pollfd watch[MaxClients + 1];
    while (running) {
        watch[0].fd = listener;
        watch[0].events = POLLIN;
        std::size_t count = 1;
        for (Clients::iterator it = clients.begin(); it != clients.end(); ++it) {
            const Client &c = it->second;
            watch[count].fd = c.fd;
            watch[count].events = c.closing ? 0 : POLLIN;
            if (!c.output.empty())
                watch[count].events |= POLLOUT;
            ++count;
        }
        int ready = poll(watch, count, 1000);
        if (ready < 0) {
            if (errno == EINTR)
                continue;
            throw std::runtime_error("poll failed");
        }
        if (watch[0].revents & (POLLERR | POLLHUP | POLLNVAL))
            throw std::runtime_error("listening socket failed");
        if (watch[0].revents & POLLIN)
            acceptOne();
        for (std::size_t i = 1; i < count; ++i) {
            if (watch[i].revents)
                handleEvents(clients.find(watch[i].fd)->second, watch[i].revents);
        }
        removeClosed();
    }
}

void Server::handleEvents(Client &c, short events) {
    if (events & (POLLERR | POLLNVAL)) {
        c.dead = true;
        return;
    }
    try {
        if ((events & POLLIN) && !c.closing && !c.dead)
            readOne(c);
        if ((events & POLLOUT) && !c.dead && !c.output.empty())
            writeOne(c);
        if ((events & POLLHUP) && !(events & POLLIN))
            c.dead = true;
    } catch (const std::bad_alloc &) {
        c.dead = true;
    }
}

void Server::readOne(Client &c) {
    char block[4096];
    ssize_t n = recv(c.fd, block, sizeof(block), 0);
    if (n < 0) {
        c.dead = true;
        return;
    }
    if (n == 0) {
        c.closing = true; // flush any outstanding replies before closing
        return;
    }
    c.input.append(block, n);
    std::size_t end;
    while (!c.closing && !c.dead && (end = c.input.find('\n')) != std::string::npos) {
        std::string line = c.input.substr(0, end);
        c.input.erase(0, end + 1);
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        if (line.size() > MaxLine || line.find('\0') != std::string::npos ||
            line.find('\r') != std::string::npos) {
            reply(c, "417", ":Invalid input line");
            c.closing = true;
        } else
            dispatch(c, line);
    }
    // A legal 510-byte payload may still be waiting for LF after its CR.
    if (!c.closing && c.input.size() > MaxLine &&
        !(c.input.size() == MaxLine + 1 && c.input[MaxLine] == '\r')) {
        reply(c, "417", ":Input line too long");
        c.closing = true;
    }
}

void Server::writeOne(Client &c) {
    ssize_t n = send(c.fd, c.output.data(), c.output.size(), 0);
    if (n > 0)
        c.output.erase(0, n);
    else
        c.dead = true;
}

// Keep a UTF-8 character together when a byte limit falls inside it.
std::size_t fitBytes(const std::string &text, std::size_t start, std::size_t maximum) {
    if (text.size() - start <= maximum)
        return text.size() - start;
    std::size_t n = maximum;
    while (n > 0 && (static_cast<unsigned char>(text[start + n]) & 0xC0) == 0x80)
        --n;
    return n ? n : maximum;
}

void Server::queue(Client &c, const std::string &line) {
    if (c.dead || c.closing)
        return;
    std::string packet = line.substr(0, fitBytes(line, 0, MaxLine)) + "\r\n";
    if (c.output.size() + packet.size() > MaxOutput) {
        c.dead = true;
        return;
    }
    c.output += packet;
}

void Server::reply(Client &c, const std::string &code, const std::string &text) {
    std::string target = c.nick.empty() ? "*" : c.nick;
    queue(c, ":irc.local " + code + " " + target + " " + text);
}

void Server::toChannel(const Channel &ch, const std::string &line, int skipFd) {
    for (Members::const_iterator it = ch.members.begin(); it != ch.members.end(); ++it) {
        if (it->first != skipFd)
            queue(clients.find(it->first)->second, line);
    }
}

void Server::toPeers(const Client &c, const std::string &line, bool includeSelf) {
    std::set<int> recipients;
    for (Channels::const_iterator it = channels.begin(); it != channels.end(); ++it) {
        const Members &members = it->second.members;
        if (members.count(c.fd)) {
            for (Members::const_iterator m = members.begin(); m != members.end(); ++m)
                recipients.insert(m->first);
        }
    }
    if (includeSelf)
        recipients.insert(c.fd);
    else
        recipients.erase(c.fd);
    for (std::set<int>::iterator it = recipients.begin(); it != recipients.end(); ++it)
        queue(clients.find(*it)->second, line);
}

void Server::removeClient(Client &c) {
    try {
        if (c.registered)
            toPeers(c, c.prefix() + " QUIT :" + c.quitReason, false);
    } catch (const std::bad_alloc &) {
        // The membership and fd cleanup below needs no new allocation.
    }
    for (Channels::iterator it = channels.begin(); it != channels.end();) {
        Channels::iterator current = it++;
        current->second.invited.erase(c.fd);
        current->second.members.erase(c.fd);
        if (current->second.members.empty())
            channels.erase(current);
    }
    close(c.fd);
}

void Server::removeClosed() {
    for (Clients::iterator it = clients.begin(); it != clients.end();) {
        Clients::iterator current = it++;
        Client &c = current->second;
        if (c.dead || (c.closing && c.output.empty())) {
            removeClient(c);
            clients.erase(current);
        }
    }
}
