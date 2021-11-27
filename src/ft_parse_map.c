/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:51:24 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/27 16:16:08 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_char_count	*set_zero(t_char_count *char_count)
{
	char_count = malloc(sizeof(t_char_count));
	char_count->C = 0;
	char_count->E = 0;
	char_count->P = 0;

	return (char_count);
}

int	valid_walls(char *line, int line_num)
{
	int i;
	int last;

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

int	valid_chars(char *line, t_char_count *char_count)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'E') 
			char_count->E++;
		else if (line[i] == 'C')
			char_count->C++;
		else if (line[i] == 'P')
			char_count->P++;
		else if (line[i] == '0' || line[i] == '1' || line[i] == '\n')
			continue;
		else
		{
			printf("ret\n");
			return (0);
		}
	}
	return (1);
}

void	set_map(int char_len, int line_len, mlx_data *g_dat)
{
	g_dat->wn_wdt = (char_len - 1) * 32;
	g_dat->wn_len = line_len * 32;
}

int		ft_parse_map(char *map, mlx_data *g_dat)
{
	int				fd;
	char			*line;
	int				i;
	size_t			len;

	fd = open(map, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	len = ft_strlen(line);
	g_dat->char_count = set_zero(g_dat->char_count);
	while (line && ++i)
	{
		if (valid_walls(line, i) && valid_chars(line, g_dat->char_count)
				&& (ft_strlen(line) == len || (ft_strlen(line) == len - 1
					&& !ft_strchr(line, '\n'))))
			line = get_next_line(fd);
		else
			return 0;
	}
	if (!g_dat->char_count->C || !g_dat->char_count->E || !g_dat->char_count->P)
		return	0;
	set_map(len, i, g_dat);
	return (1);
}
