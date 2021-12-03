NAME=so_long
CC=gcc -Wall -Werror -Wextra
SRC=ft_parse_map.c \
				main.c \
				ft_parse_map.c \
				start_game.c \
				get_next_line.c \
				get_next_line_utils.c \

SRC_PATH=$(addprefix src/, $(SRC))

SRC_OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	cd libft; make re; make clean;
	$(CC) -c $(SRC_PATH)
	$(CC) *.o -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(SRC_OBJ)

re: fclean
	make

%.o: %.c
