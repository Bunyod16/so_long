/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:43:12 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/27 21:43:11 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    init_map(map_opts *opts)
{
    opts->x = 0;
    opts->y = 0;
}

int deal_key(int key, mlx_data *g_dat)
{
    if (key == W)
        printf("w\n");
    else if (key == A)
        printf("a\n");
    else if (key == S)
        printf("s\n");
    else if (key == D)
        printf("d\n");
    else
        mlx_clear_window(g_dat->mlx_ptr, g_dat->wn);
    return (0);
}

char    **init_layout(char *map, int y)
{
    int     fd;
    char    *line;
    char    **layout;
    int     i;

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

int main(int argc, char **argv)
{
    map_opts    *opts = NULL;
    mlx_data    g_dat;
    
    opts = malloc(sizeof(map_opts *));
    init_map(opts);
    if (argc != 2 || !ft_parse_map(argv[1], &g_dat) || g_dat.wn_len == 0)
    {    
        write(2, "Error", 5);
        return (0);
    }
    g_dat.layout = init_layout(argv[1], opts->y);
    g_dat.mlx_ptr = mlx_init();
    g_dat.wn = mlx_new_window(g_dat.mlx_ptr, g_dat.wn_wdt, g_dat.wn_len, "42 so_long");
    mlx_key_hook(g_dat.wn, deal_key, &g_dat);
    init_game(argv[1], g_dat.mlx_ptr, g_dat.wn, &g_dat);
    mlx_loop(g_dat.mlx_ptr);
}