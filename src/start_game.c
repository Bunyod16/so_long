/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:00:51 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/12/03 03:11:24 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_mlx_data *g)
{
	end_game(g);
	return (1);
}

void	init_game(t_mlx_data *game_dat)
{
	char	*line;
	int		i;
	int		y;

	y = -1;
	while (game_dat->layout[++y])
	{
		i = -1;
		line = game_dat->layout[y];
		while (line[++i])
		{
			if (line[i] == 'C' || line[i] == 'E'
				|| line[i] == 'P' || line[i] == 'L')
				ft_put_image('0', i * 32, y * 32, game_dat);
			ft_put_image(line[i], i * 32, y * 32, game_dat);
		}
	}
}

void	ft_put_image(char c, int x, int y, t_mlx_data *g)
{
	void	*img_ptr;

	if (c == '0')
		img_ptr = g->f;
	else if (c == '1')
		img_ptr = g->w;
	else if (c == 'P')
	{
		g->player.x = x;
		g->player.y = y;
		img_ptr = g->p2;
	}
	else if (c == 'L')
	{
		g->player.x = x;
		g->player.y = y;
		img_ptr = g->p1;
	}
	else if (c == 'C')
		img_ptr = g->c;
	else
		img_ptr = g->e;
	mlx_put_image_to_window(g->mlx_ptr, g->wn, img_ptr, x, y);
}
