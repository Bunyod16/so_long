/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:43:12 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/12/03 03:12:30 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_mlx_data *g)
{
	if (g->player.coins == g->char_count.c)
		ft_putstr_fd("You Win!\n", 1);
	else
		ft_putstr_fd("You Loose!\n", 1);
	mlx_destroy_image(g->mlx_ptr, g->p1);
	mlx_destroy_image(g->mlx_ptr, g->p2);
	mlx_destroy_image(g->mlx_ptr, g->c);
	mlx_destroy_image(g->mlx_ptr, g->f);
	mlx_destroy_image(g->mlx_ptr, g->w);
	mlx_destroy_image(g->mlx_ptr, g->e);
	mlx_clear_window(g->mlx_ptr, g->wn);
	mlx_destroy_window(g->mlx_ptr, g->wn);
	free(g->mlx_ptr);
	exit(1);
}

void	move_player(t_mlx_data *g, int new_x, int new_y)
{
	const int	old_x = (g->player.x) / 32;
	const int	old_y = (g->player.y) / 32;
	char		direction;

	direction = 'L';
	if (new_x > old_x)
		direction = 'P';
	if (g->layout[new_y][new_x] == 'C')
		g->player.coins += 1;
	if (g->layout[new_y][new_x] == 'E')
	{
		if (g->player.coins == g->char_count.c)
			end_game(g);
		g->layout[old_y][old_x] = direction;
		g->layout[new_y][new_x] = 'E';
	}
	else
	{
		g->layout[old_y][old_x] = '0';
		g->layout[new_y][new_x] = direction;
		g->moves += 1;
	}
}

int	deal_key(int key, t_mlx_data *g)
{
	const int	x = (g->player.x) / 32;
	const int	y = (g->player.y) / 32;

	if (key == W && g->layout[y - 1][x] != '1')
		move_player(g, x, y - 1);
	else if (key == A && g->layout[y][x - 1] != '1')
		move_player(g, x - 1, y);
	else if (key == S && g->layout[y + 1][x] != '1')
		move_player(g, x, y + 1);
	else if (key == D && g->layout[y][x + 1] != '1')
		move_player(g, x + 1, y);
	else if (key == ESC)
		end_game(g);
	mlx_clear_window(g->mlx_ptr, g->wn);
	init_game(g);
	mlx_string_put(g->mlx_ptr, g->wn, 10, 15, 0x00FFFFFF, ft_itoa(g->moves));
	return (0);
}

char	**init_layout(char *map, int y)
{
	int		fd;
	char	*line;
	char	**layout;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	layout = malloc(sizeof(char *) * (y + 1));
	while (line)
	{
		layout[i] = line;
		i++;
		line = get_next_line(fd);
	}
	layout[i] = NULL;
	return (layout);
}

int	main(int argc, char **argv)
{
	t_mlx_data	g;
	void		*(*func)(void *, char *, int *, int *);

	if (argc != 2 || !ft_parse_map(argv[1], &g) || g.wn_len == 0)
	{
		write(2, "Error", 5);
		return (0);
	}
	g.layout = init_layout(argv[1], g.wn_wdt / 4);
	g.mlx_ptr = mlx_init();
	g.wn = mlx_new_window(g.mlx_ptr, g.wn_wdt, g.wn_len, "42 so_long");
	func = mlx_png_file_to_image;
	g.p1 = func(g.mlx_ptr, "pic/p1.png", &g.img_wd, &g.img_len);
	g.p2 = func(g.mlx_ptr, "pic/p2.png", &g.img_wd, &g.img_len);
	g.c = func(g.mlx_ptr, "pic/coin.png", &g.img_wd, &g.img_len);
	g.w = func(g.mlx_ptr, "pic/wall.png", &g.img_wd, &g.img_len);
	g.f = func(g.mlx_ptr, "pic/floor.png", &g.img_wd, &g.img_len);
	g.e = func(g.mlx_ptr, "pic/exit.png", &g.img_wd, &g.img_len);
	mlx_key_hook(g.wn, deal_key, &g);
	mlx_hook(g.wn, 17, 0, close_window, &g);
	init_game(&g);
	mlx_loop(g.mlx_ptr);
}
