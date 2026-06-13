NAME = miniRT

INC_DIR = . src/libft/inc minilibx-linux
SRC_DIR = src
OBJ_DIR = obj

SRC = \
	main.c utils/free.c \
	utils/rt_math.c utils/rt_math2.c utils/rt_math3.c utils/rt_math4.c \
	utils/rt_math5.c utils/rt_math_intersection.c \
	utils/set_surface_quadrics.c utils/set_surface_params.c utils/surface.c \
	draw/draw.c draw/window.c draw/img_buffer.c \
	draw/key_hook.c ray/raytrace.c ray/raytrace_calc.c \
	ray/raytrace_calc2.c draw/render.c \
	val/val_element.c val/val_element2.c \
	val/val_input.c val/val_obj.c \
	val/val_scene.c \
	parser/parse_scene.c parser/parse_objects.c parser/parse_values.c

SRC := $(addprefix $(SRC_DIR)/,$(SRC))
OBJS := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS_TARGET = src/libft/libft.a minilibx-linux/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(addprefix -I,$(INC_DIR))
LDFLAGS = -Lsrc/libft -Lminilibx-linux
LDLIBS = -lft -lmlx -lm -lXext -lX11

DEBUG ?= 0
ifeq ($(DEBUG),1)
	CFLAGS += -g3 -O0
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

valgrind-run:
	@valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--track-fds=yes \
		--trace-children=yes \
		--trace-children-skip='*/bin/*,*/sbin/*,/usr/bin/*' \
		./$(NAME) $(INPUT)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C src/libft fclean
	rm -f minilibx-linux/libmlx.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re