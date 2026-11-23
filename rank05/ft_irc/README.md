*This project has been created as part of the 42 curriculum by thitoe, hakama.*

# ft_irc

## Description

`ircserv` is a single-server IRC chat service written in C++98. Clients connect over IPv4 TCP, register with a server password, choose a nickname and username, join channels and exchange messages. The first user to join a new channel becomes its operator. All sockets use non-blocking I/O and share one poll loop.

## Instructions

Use a Unix system with a C++ compiler and make. The server uses the C++98 standard library and POSIX sockets.

```sh
make
./ircserv 6667 school42
```

The arguments are the TCP port (1–65535) and the connection password. The server listens on all local IPv4 interfaces. Use Ctrl+C in the server terminal to stop it. `make clean` removes object files, `make fclean` also removes the executable, and `make re` rebuilds it.

### Reference client

Use **sic** (suckless simple IRC client). On macOS with Homebrew, run `brew install sic`. On Debian, the package is named `sic`. The upstream source can also be built in your own directory with `make` and run as `./sic`.

In two additional terminals, start a separate client for each nickname.

```sh
sic -h 127.0.0.1 -p 6667 -n alice -k school42
sic -h 127.0.0.1 -p 6667 -n bob   -k school42
```

Type `:j #lab` in Alice's terminal first, then in Bob's. Alice can type a normal line to speak to the channel, `:m bob hello` to send Bob a private message, or `:MODE #lab +o bob` to grant Bob operator privileges. In sic a leading colon sends a raw command. Use `:QUIT :bye` to disconnect.

For a wire-level check, run `nc 127.0.0.1 6667` in another terminal and enter the following lines. This server accepts both CRLF and LF as input and sends CRLF on every reply.

```text
PASS school42
NICK carol
USER carol 0 * :Carol Example
JOIN #lab
PRIVMSG #lab :hello from Carol
```

### Channel commands

| Command | Effect |
| --- | --- |
| `JOIN #lab [key]`, `PART #lab [:reason]` | Enter or leave a channel. Empty channels disappear. |
| `PRIVMSG bob :text`, `PRIVMSG #lab :text` | Send to one user or to the other members of a channel. Comma-separated targets are supported. |
| `TOPIC #lab`, `TOPIC #lab :text` | View or set the topic. A trailing colon alone clears it. |
| `INVITE bob #lab`, `KICK #lab bob :reason` | An operator can invite a user or remove a member. Invitations are consumed on successful join. |
| `MODE #lab +i`, `MODE #lab -i` | Require or stop requiring invitations. |
| `MODE #lab +t`, `MODE #lab -t` | Restrict topic edits to operators or allow all members to edit. New channels start with `+t`. |
| `MODE #lab +k blue`, `MODE #lab -k` | Set or clear a channel key. |
| `MODE #lab +o bob`, `MODE #lab -o bob` | Grant or revoke operator status within this channel. |
| `MODE #lab +l 3`, `MODE #lab -l` | Limit the total member count or remove that limit. |

## Resources

- The supplied **ft_irc subject v11.0**, particularly IV.1–IV.3, V and VII, defines the assignment and the defense.
- IRC registration, commands, and numeric replies. [RFC 2812](https://www.rfc-editor.org/rfc/rfc2812)
- Message framing and client conventions. [Modern IRC Client Protocol](https://modern.ircdocs.horse/)
- Startup feature negotiation. [IRCv3 capability negotiation](https://ircv3.net/specs/extensions/capability-negotiation.html)
- Socket readiness and event flags. [poll(2)](https://man7.org/linux/man-pages/man2/poll.2.html)
- Reference-client documentation and source. [sic](https://tools.suckless.org/sic/)

AI assisted with interpreting the subject, drafting the event loop and command handlers, producing the learning notes, and designing and running local interoperability and regression tests. These tasks included partial input and output, channel permissions, and disconnect cleanup.
