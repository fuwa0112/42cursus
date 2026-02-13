# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 13:55:43 by thitoe            #+#    #+#              #
#    Updated: 2026/02/12 14:29:39 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

# Paths and Files
ifeq ($(UNAME), Darwin)
	MLX_PATH = ./mlx_metal
	MLX_LIB = $(MLX_PATH)/libmlx.dylib
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework Metal -framework AppKit
	POST_BUILD = @cp $(MLX_LIB) ./libmlx.dylib
	POST_FCLEAN = @rm -f ./libmlx.dylib && $(MAKE) -C $(MLX_PATH) fclean
else ifeq ($(UNAME), Linux)
	MLX_PATH = ./mlx
	MLX_LIB = $(MLX_PATH)/libmlx.a
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 
	POST_BUILD =
	POST_FCLEAN =
else
	$(error $(shell printf "\033[31mUnsupported OS: $(UNAME)\033[0m"))
endif

NAME = miniRT

MAIN = src/main.c
LIBFT_PATH = src/libft
LIBFT = ${LIBFT_PATH}/libft.a
GNL_PATH = src/get_next_line
INIT_PATH = src/init
PARSE_PATH = src/parsing
UTIL_PATH = src/utils
FREE_PATH = src/free
VEC_PATH = src/vector
RENDER_PATH = src/render
INTERSECTION_PATH = src/intersection
OBJ_DIR = obj

SRCS = ${MAIN} \
${GNL_PATH}/get_next_line.c ${GNL_PATH}/get_next_line_utils.c \
${INIT_PATH}/init_data.c ${INIT_PATH}/init_viewport.c\
${PARSE_PATH}/parsing.c\
${UTIL_PATH}/count.c ${UTIL_PATH}/create.c ${UTIL_PATH}/color_utils.c ${UTIL_PATH}/ray.c ${UTIL_PATH}/color_utils_extra.c ${UTIL_PATH}/utils_extra.c ${UTIL_PATH}/camera_position_check.c\
${UTIL_PATH}/ambient.c ${UTIL_PATH}/camera.c ${UTIL_PATH}/cylinder.c ${UTIL_PATH}/cylinder_utils.c ${UTIL_PATH}/light.c ${UTIL_PATH}/plane.c ${UTIL_PATH}/sphere.c ${UTIL_PATH}/sphere_utils.c ${UTIL_PATH}/light_position_check.c\
${UTIL_PATH}/utils.c ${UTIL_PATH}/validation.c ${UTIL_PATH}/validation_utils.c ${UTIL_PATH}/mlx_window_utils.c ${UTIL_PATH}/display_utils.c ${UTIL_PATH}/create_utils.c ${UTIL_PATH}/create_utils_extra.c\
${FREE_PATH}/free.c\
${VEC_PATH}/vector.c ${VEC_PATH}/vector_extra.c\
${RENDER_PATH}/render.c ${RENDER_PATH}/render_utils.c ${RENDER_PATH}/render_mlx_utils.c \
${RENDER_PATH}/render_computations.c ${RENDER_PATH}/shadow_utils.c ${RENDER_PATH}/render_scene.c\
${INTERSECTION_PATH}/intersect_sphere.c ${INTERSECTION_PATH}/intersect_plane.c ${INTERSECTION_PATH}/intersect_cylinder.c \
${INTERSECTION_PATH}/intersect_cylinder_utils.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

INCLUDES = -Iincludes

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) ${MLX_LIB} ${LIBFT}
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) ${MLX_FLAGS} -L$(LIBFT_PATH) ${LIBFT} ${MLX_LIB} -lm -o $(NAME)
	$(POST_BUILD)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	@echo "\033[33m[Cleaned up]\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(POST_FCLEAN)
	@echo "\033[33m[Fully cleaned up]\033[0m"

re: fclean all

.PHONY: all clean fclean re
