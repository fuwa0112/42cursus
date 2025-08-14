# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 00:00:49 by thitoe            #+#    #+#              #
#    Updated: 2025/06/18 00:00:53 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
CFLAG = -Wall -Wextra -Werror
SRCS = ft_judgment.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_write_pointer.c
OBJS = $(SRCS:.c=.o)
RM = rm

all : $(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAG) -c $< -o $@

clean:
		$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f libftprintf.a

re: fclean all

.PHONY: all clean fclean re