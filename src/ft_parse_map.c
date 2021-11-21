/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:51:24 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/21 03:28:53 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_rectangle(int fd)
{
	char		*buf;
	int			len;
	int			temp;

	buf = malloc(sizeof(char *) * 2);
	len = 0;
	temp = 0;
	while (read(fd, buf, 1) > 0)
	{
		if (*buf == '\n')
		{
			if (len == 0)
				len = temp;
			if (temp == len)
				temp = 0;
			else
				break ;
		}
		else
			temp++;
	}
	free (buf);
	if (len == 0 || temp != len)
		return (0);
	return (1);
}

int	map_check_walls(char *map)
{
	char		*buf;
	int			ln;
	int			c_num;
	const int	fd = open(map, O_RDONLY);

	buf = malloc(sizeof(char *) * 2);
	ln = 1;
	c_num = 1;
	while (read(fd, buf, 1) > 0)
	{
		if ((((ln == max_ln(map) || ln == 1) && c_num != max_chr(map) + 1)
				|| c_num == 1 || c_num == max_chr(map)) && *buf != '1')
		{
			free(buf);
			return (0);
		}
		if (*buf == '\n')
		{
			c_num = 1;
			ln++;
		}
		else
			c_num++;
	}
	free(buf);
	return (1);
}

int	map_check_chars(int fd)
{
	char			*buf;
	t_char_count	*char_count;

	buf = malloc(sizeof(char *) * 2);
	char_count = malloc(sizeof(t_char_count *));
	set_zero(char_count);
	while(read(fd, buf, 1) > 0)
	{
		if (*buf == '0' || *buf == '1' || *buf=='C' || *buf=='E' || *buf=='P' || *buf=='\n')
		{
			if (*buf == 'E')
				char_count->E = 1;
			else if (*buf == 'C')
				char_count->C = 1;
			else if (*buf == 'P')
				char_count->P = 1;
		}
		else
		{
			set_zero(char_count);
			break;
		}
	}
	free(buf);
	return (!char_count->C || !char_count->E || !char_count->P);
}

int	ft_parse_map(int argc, char **argv)
{
	int			fd;
	char		*buf;

	if (argc != 2)
		return (0);
	if (map_rectangle(open(argv[1], O_RDONLY)) == 0)
		return (0);
	if (map_check_walls(argv[1]) == 0)
		return (0);
	if (map_check_chars(open(argv[1], O_RDONLY)) == 0)
		return (0);
	buf = malloc(sizeof(char *) * 2);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buf, 1) > 0)
	{
		printf("%c",*buf);
	}
	printf("passed map check\n");
	return (1);
}
