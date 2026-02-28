# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 14:46:28 by thitoe            #+#    #+#              #
#    Updated: 2026/02/28 15:34:45 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = minilibx-linux

MLX = $(MLX_DIR)/libmlx.a

SRCS = main.c \
	utils/ft_split.c utils/ft_splitspace.c utils/get_next_line.c \
	vectors/vec_op2.c vectors/vector_op.c \
	parsing/parse_camera.c parsing/parse_object.c \
	parsing/parse_options.c parsing/parsing.c \
	utils/utils.c utils/utils2.c \
	parsing/parse_light.c camera.c \
	utils/utils3.c objects/cylinder.c \
	objects/cyl_utils.c objects/plan.c \
	mlx_hooks.c lightning.c \
	raytracing.c objects/sphere.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I. -Isrc -I$(MLX_DIR)

LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LDFLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re