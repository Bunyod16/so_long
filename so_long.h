/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:32:29 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/27 20:17:11 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#define BUFFER_SIZE 1
#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53

typedef struct  s_char_count
{
    int C;
    int E;
    int P;
}   t_char_count;

typedef struct  s_coords
{
    void    *img_ptr;
    int     x;
    int     y;
}   t_xy;

typedef struct  s_mlx_data
{
    char            **layout;
    void            *mlx_ptr;
    void            *wn;
    int             wn_wdt;
    int             wn_len;
    t_char_count    *char_count;
    t_xy            player;
}   mlx_data;

typedef struct s_map_opts
{
    int x;
    int y;
}   map_opts;

int		ft_parse_map(char *map, mlx_data *g_dat);
void    ft_put_image(void *mlx_ptr, void *win_ptr, char c, int x, int y, mlx_data *game_dat);
void    init_game(char *map, void *mlx_ptr, void *win_ptr, mlx_data *game_dat);
int     max_chr(char *map);
int     max_ln(char *map);
char	*get_next_line(int fd);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(const char *s1);
size_t	gnl_strlen(const char *s);
int     gnl_strchr(const char *s, int c);

# endif