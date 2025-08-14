# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 22:41:21 by thitoe            #+#    #+#              #
#    Updated: 2025/08/15 02:06:36 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lXext -lX11 -lm
RM = rm -rf

SRCS = srcs/julia.c \
       srcs/main.c \
       srcs/burning_ship.c \
       srcs/utils.c \
       srcs/instructions.c \
       srcs/mandelbrot.c \
       srcs/atoi.c \
       srcs/init.c \
	   srcs/menu.c


OBJ = $(SRCS:.c=.o)

PRINTF = ft_printf/libftprintf.a
MINILIBX = minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx.a
LIBS = $(PRINTF) $(MINILIBX)

all: $(PRINTF) $(MINILIBX) $(NAME)

$(PRINTF):
	@make -s -C ft_printf/

$(MINILIBX):
	@make -s -C minilibx-linux/

$(NAME): $(OBJ) $(PRINTF) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LDFLAGS) -o $(NAME)
	@$(RM) srcs/*.o
	@echo "$(NAME) built successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) srcs/*.o
	@make -s -C ft_printf/ clean
	@make -s -C minilibx-linux/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C  ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re