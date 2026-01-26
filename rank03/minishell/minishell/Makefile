CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LDFLAGS = -lreadline
NAME = minishell

SRC_DIR = .
OBJ_DIR = obj

BUILTIN   = builtin builtin1 builtin2 builtin3 builtin4 builtin5 builtin6 builtin7 builtin8
EXECUTOR  = executor executor1 executor2 executor3
EXPANDER  = expander expander1 expander2
HEREDOC = heredoc heredoc1
PARSER    = parser parser1
UTILS     = utils utils1 utils2 utils3 utils4 utils5 utils6 utils7 utils8

SRC = \
	$(addprefix src/builtin/, $(addsuffix .c, $(BUILTIN))) \
	$(addprefix src/executor/, $(addsuffix .c, $(EXECUTOR))) \
	$(addprefix src/expander/, $(addsuffix .c, $(EXPANDER))) \
	$(addprefix src/heredoc/, $(addsuffix .c, $(HEREDOC))) \
	$(addprefix src/parser/, $(addsuffix .c, $(PARSER))) \
	$(addprefix src/utils/, $(addsuffix .c, $(UTILS))) \
	src/ft_split.c \
	main.c \
	src/signal.c \
	src/tokenizer.c \

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
