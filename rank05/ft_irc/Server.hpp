#ifndef SERVER_HPP
#define SERVER_HPP

#include <csignal>
#include <cstddef>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

typedef std::vector<std::string> Words;
typedef std::map<int, bool> Members; // fd -> has channel operator privileges

struct Client {
    int fd;
    std::string host, nick, user, realName;
    std::string input, output, quitReason;
    bool hasPass, registered, negotiating, closing, dead;

    Client(int socketFd, const std::string &address);
    std::string prefix() const;
};

struct Channel {
    std::string name, topic, key;
    bool inviteOnly, topicLocked;
    int limit; // 0 means unlimited
    Members members;
    std::set<int> invited;

    explicit Channel(const std::string &channelName);
};

std::string lowerName(std::string name);
int positiveNumber(const std::string &text, int maximum);
Words commaList(const std::string &text);
std::size_t fitBytes(const std::string &text, std::size_t start, std::size_t maximum);

class Server {
public:
    explicit Server(const std::string &password);
    ~Server();
    void run(int port, const volatile std::sig_atomic_t &running);

private:
    typedef std::map<int, Client> Clients;
    typedef std::map<std::string, Channel> Channels;
    enum { MaxClients = 256, MaxLine = 510, MaxOutput = 1024 * 1024 };

    int listener;
    std::string password;
    Clients clients;
    Channels channels;

    Server(const Server &);
    Server &operator=(const Server &);

    void listenOn(int port);
    void acceptOne();
    void readOne(Client &c);
    void writeOne(Client &c);
    void handleEvents(Client &c, short events);
    void removeClosed();
    void removeClient(Client &c);

    void queue(Client &c, const std::string &line);
    void reply(Client &c, const std::string &code, const std::string &text);
    void toChannel(const Channel &ch, const std::string &line, int skipFd);
    void toPeers(const Client &c, const std::string &line, bool includeSelf);
    Client *findNick(const std::string &nick);

    void dispatch(Client &c, const std::string &line);
    bool need(Client &c, const Words &w, std::size_t count);
    void registerCommand(Client &c, const Words &w);
    void welcome(Client &c);
    void nick(Client &c, const std::string &newNick);
    void cap(Client &c, const Words &w);
    void privmsg(Client &c, const Words &w);
    void deliverMessage(Client &c, const std::string &target, const std::string &text);

    Channel *memberChannel(Client &c, const std::string &name);
    bool requireOp(Client &c, const Channel &ch);
    void join(Client &c, const Words &w);
    void joinOne(Client &c, const std::string &name, const std::string &key);
    void part(Client &c, const Words &w);
    void leave(Channel &ch, int fd);
    void names(Client &c, const Channel &ch);
    void who(Client &c, const std::string &name);
    void topic(Client &c, const Words &w);
    void invite(Client &c, const Words &w);
    void kick(Client &c, const Words &w);

    void mode(Client &c, const Words &w);
    void showModes(Client &c, const Channel &ch);
    bool changeMode(Client &c, Channel &ch, char flag, bool adding,
                    std::string &value);
};

#endif
