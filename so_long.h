/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:32:29 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/12/05 02:32:47 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFFER_SIZE 1
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_char_count
{
	int	c;
	int	e;
	int	p;
}	t_char_count;

typedef struct s_player
{
	int	x;
	int	y;
	int	coins;
}	t_player;

typedef struct s_mlx_data
{
	void			*p1;
	void			*p2;
	void			*c;
	void			*e;
	void			*w;
	void			*f;
	char			**layout;
	void			*mlx_ptr;
	void			*wn;
	int				wn_wdt;
	int				wn_len;
	int				moves;
	int				img_wd;
	int				img_len;
	t_char_count	char_count;
	t_player		player;
}	t_mlx_data;

typedef struct s_map_opts
{
	int	x;
	int	y;
}	t_map_opts;

int		end_with_nl(char *map);
int		close_window(t_mlx_data *g);
void	end_game(t_mlx_data *g);
int		ft_parse_map(char *map, t_mlx_data *g_dat);
void	ft_put_image(char c, int x, int y, t_mlx_data *game_dat);
void	init_game(t_mlx_data *game_dat);
int		max_chr(char *map);
int		max_ln(char *map);
char	*get_next_line(int fd);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(const char *s1);
size_t	gnl_strlen(const char *s);
int		gnl_strchr(const char *s, int c);
void	set_data(int char_len, int line_len, t_mlx_data *g_dat);
void	set_zero(t_mlx_data *g_dat);

#endif