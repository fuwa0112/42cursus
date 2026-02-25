# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 06:22:26 by thitoe            #+#    #+#              #
#    Updated: 2026/02/25 21:53:11 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain
CC = c++
STD = -std=c++98 -pedantic
FLAGS = -Wall -Wextra -Werror
SANITIZE = -g -fsanitize=address

SRC_NAME =	main.cpp \

OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(STD) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "Compilation done."

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(STD) $(FLAGS) -c $< -I. -o $@

clean:
	@rm -f $(OBJ)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed binary files"

re: fclean all

.PHONY: all clean fclean re
