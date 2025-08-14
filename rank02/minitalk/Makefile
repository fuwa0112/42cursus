# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 12:49:17 by thitoe            #+#    #+#              #
#    Updated: 2025/08/15 05:38:01 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c
FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_PATH)/libftprintf.a
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(FT_PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(FT_PRINTF_PATH) -lftprintf

$(SERVER_NAME): $(SERVER_SRCS) $(FT_PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(FT_PRINTF_PATH) -lftprintf

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS) $(FT_PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) -L$(FT_PRINTF_PATH) -lftprintf

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS) $(FT_PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) -L$(FT_PRINTF_PATH) -lftprintf

$(FT_PRINTF_ARCHIVE):
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

.PHONY: all clean fclean re bonus
