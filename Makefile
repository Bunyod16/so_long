NAME = so_long
CC = gcc -Wall -Werror -Wextra
SRC = ft_parse_map.c \
				main.c \
				start_game.c \
				get_next_line.c \
				get_next_line_utils.c \

SRC_PATH=$(addprefix src/, $(SRC))

SRC_OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	cd libft; make re; make clean;
	cd minilibx; make;
	$(CC) -c $(SRC_PATH)
	$(CC) $(SRC_OBJ) -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(SRC_OBJ)

test:
	@echo *.o

re: fclean
	make

%.o: %.c
