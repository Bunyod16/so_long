/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:00:51 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/27 21:43:18 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_game(char *map, void *mlx_ptr, void *win_ptr, mlx_data *game_dat)
{
    int fd;
    char *line;
    int i;
    int len;
    int y;

    fd = open(map, O_RDONLY);
    line = get_next_line(fd);
    len = ft_strlen(line);
    y = -1;
    while (line)
    {
        y++;
        i = -1;
        while (line[++i])
        {
            if (line[i] == 'C' || line[i] == 'E' || line[i] == 'P')
                ft_put_image(mlx_ptr, win_ptr, '0', i*32, y*32, game_dat);
            ft_put_image(mlx_ptr, win_ptr, line[i], i*32, y*32, game_dat);
        }
        line = get_next_line(fd);
    }
}

void    ft_put_image(void *mlx_ptr, void *win_ptr, char c, int x, int y, mlx_data *game_dat)
{
    void    *img_ptr;
    int     wdt;
    int     hgt;
    char    *img_dir = NULL;

    img_ptr = malloc(sizeof(void *));
    if (c == '0')
        img_dir = "assets/floor.png";
    else if (c == '1')
        img_dir = "assets/wall.png";
    else if (c == 'P')
        img_dir = "assets/player.png";
    else if (c == 'C')
        img_dir = "assets/c1.png";
    else if (c == 'E')
        img_dir = "assets/door_white.png";
    else
        img_dir = "assets/c1.png";
    img_ptr = mlx_png_file_to_image(mlx_ptr, img_dir, &wdt, &hgt);
    if (c == 'P')
    {
        game_dat->player.img_ptr = img_ptr;
        game_dat->player.x = x;
        game_dat->player.y = y;
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
}