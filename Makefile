NAME=so_long
CC=gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	cd libft; make re; make clean;
	$(CC) -c src/*.c
	$(CC) *.o -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit -lz -o so_long

fclean: clean
	rm -rf so_long

clean:
	rm -rf  *.o

re: fclean
	make

%.o: %.c
