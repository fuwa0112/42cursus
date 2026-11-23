#include "Server.hpp"
#include <exception>
#include <iostream>

static volatile std::sig_atomic_t running = 1;

static void stop(int) {
    running = 0;
}

int positiveNumber(const std::string &text, int maximum) {
    int result = 0;
    for (std::size_t i = 0; i < text.size(); ++i) {
        if (text[i] < '0' || text[i] > '9')
            return 0;
        int digit = text[i] - '0';
        if (result > (maximum - digit) / 10)
            return 0;
        result = result * 10 + digit;
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: ./ircserv <port> <password>\n";
        return 1;
    }
    try {
        int port = positiveNumber(argv[1], 65535);
        std::string password(argv[2]);
        if (!port || password.empty() || password.size() > 504 ||
            password.find_first_of("\r\n") != std::string::npos) {
            std::cerr << "Use port 1..65535 and a nonempty IRC password (max 504 bytes).\n";
            return 1;
        }
        std::signal(SIGINT, stop);
        std::signal(SIGTERM, stop);
        std::signal(SIGPIPE, SIG_IGN);
        Server server(password);
        server.run(port, running);
    } catch (const std::exception &error) {
        std::cerr << "ircserv: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
