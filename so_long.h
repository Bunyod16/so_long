#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

struct  t_char_count
{
    int C;
    int E;
    int P;
} s_char_count;

int ft_parse_map(int argc, char **argv);
# endif