NAME=so_long
CC=gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) src/*.c -Lminilibx -lmlx -framework OpenGL -framework AppKit -lz -o so_long

clean:
	rm -rf so_long *.o

re: clean
	make

%.o: %.c
