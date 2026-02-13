# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 15:48:24 by thitoe            #+#    #+#              #
#    Updated: 2026/02/12 14:01:02 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
	ft_split2.c
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
	$(RM) -f libft.a

re: fclean all

.PHONY: all clean fclean re
