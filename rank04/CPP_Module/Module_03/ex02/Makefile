# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/22 08:42:44 by thitoe            #+#    #+#              #
#    Updated: 2026/02/25 21:53:52 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
CC = c++
FLAGS = -Wall -Wextra -Werror
NINETYEIGHT = -std=c++98 -pedantic
SANITIZE = -g -fsanitize=address

SRC_NAME =	ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			main.cpp \

INCLUDES =  ClapTrap.hpp \
			ScavTrap.hpp \
			FragTrap.hpp \

OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

SRC_DIR = ./src/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(STD) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "Compilation done."

$(OBJ_DIR)%.o: %.cpp $(INCLUDES)
	$(CC) $(STD) $(FLAGS) -c $< -I. -o $@

clean:
	@rm -f $(OBJ)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed binary files"

re: fclean all

.PHONY: all clean fclean re