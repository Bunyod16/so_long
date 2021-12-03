/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:51:24 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/12/03 22:26:06 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_extension(char *map)
{
	int len;
	int i;

	len = ft_strlen(map);
	i = len - 4;
	if (len < 5)
		return (0);
	if (map[i] == '.' && map[i + 1] == 'b' && map[i + 2] == 'e'
		&& map[i + 3] == 'r')
		return (1);
	return (0);
}

int	valid_walls(char *line, int line_num)
{
	int	i;
	int	last;

	last = ft_strlen(line) - 2;
	i = 0;
	while (line[i])
	{
		if (i == (int)ft_strlen(line) - 1 && line[i] == '\n')
			return (1);
		if ((line_num == 1 || line_num == -1) && line[i] != '1')
			return (0);
		else if ((i == 0 || i == last) && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_chars(char *line, t_mlx_data *g_dat)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'E')
			g_dat->char_count.e++;
		else if (line[i] == 'C')
			g_dat->char_count.c++;
		else if (line[i] == 'P')
			g_dat->char_count.p++;
		else if (line[i] == '0' || line[i] == '1' || line[i] == '\n')
			continue ;
		else
			return (0);
	}
	return (1);
}

int	ft_parse_map(char *map, t_mlx_data *g)
{
	const int		fd = open(map, O_RDONLY);		
	char			*line;
	int				i;
	size_t			len;

	i = 0;
	line = get_next_line(fd);
	if (!line || fd < 1)
		return (0);
	len = ft_strlen(line);
	set_zero(g);
	while (line && ++i)
	{
		if (valid_walls(line, i) && valid_chars(line, g)
			&& (ft_strlen(line) == len || (ft_strlen(line) == len - 1
					&& !ft_strchr(line, '\n'))))
			line = get_next_line(fd);
		else
			return (0);
	}
	if (!g->char_count.c || !g->char_count.e || g->char_count.p != 1
		|| !valid_extension(map))
		return (0);
	set_data(len, i, g);
	return (1);
}
