CC = gcc
CFLAGS = -Wall -Wextra -Werror 
NAME = minishell
SRC = echo.c main.c parser.c utils.c pwd.c exit.c env.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -lreadline -g -fsanitize=address

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