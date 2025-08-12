# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 22:41:21 by thitoe            #+#    #+#              #
#    Updated: 2025/08/12 23:55:32 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Imlx_linux
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
RM = rm -rf

SRCS = srcs/julia.c \
       srcs/main.c \
       srcs/burning_ship.c \
       srcs/utils.c \
       srcs/instructions.c \
       srcs/mandelbrot.c \
       srcs/atoi.c \
       srcs/init.c

PRINTF = ft_printf/libftprintf.a
LIBS = $(PRINTF) mlx_linux/libmlx_Linux.a mlx_linux/libmlx.a

OBJ = $(SRCS:.c=.o)

all: $(PRINTF) $(NAME)

$(PRINTF):
	@make -s -C ft_printf/

$(NAME): $(OBJ) $(PRINTF)
	@echo "🔨 Building $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LDFLAGS) -o $(NAME)
	@$(RM) srcs/*.o
	@echo "✅ $(NAME) built successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) srcs/*.o
	@make -s -C ft_printf/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re
