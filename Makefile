CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell
SRC = ./builtins/echo.c ./builtins/pwd.c ./builtins/exit.c ./builtins/env.c ./builtins/export.c ./builtins/exportutils.c ./builtins/unset.c  ./builtins/cd.c \
		main.c parser.c utils.c ./builtins/cdutils.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -lreadline 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re