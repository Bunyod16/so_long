/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:51:24 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/20 05:12:20 by bunyodshams      ###   ########.fr       */
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

int	find_max_chars(char *map)
{
	const int	fd = open(map, O_RDONLY);
	char		*buf;
	int			count;

	count = 0;
	buf = malloc(sizeof(char *) * 2);
	while(read(fd, buf, 1) > 0)
	{
		if (*buf == '\n')
			return (count);
		count++;
	}
	return (count);
}

int	find_line_num(char *map)
{
	const int	fd = open(map, O_RDONLY);
	char		*buf;
	int			count;

	count = 1;
	buf = malloc(sizeof(char *) * 2);
	while(read(fd, buf, 1) > 0)
	{
		if (*buf == '\n')
			count++;
	}
	return (count);
}

int map_check_walls(char *map)
{
	char		*buf;
	int			line;
	int			char_num;
	const int	fd = open(map, O_RDONLY);
	const int	last_c = find_max_chars(map);
	const int	last_l = find_line_num(map);

	buf = malloc(sizeof(char *) * 2);
	line = 1;
	char_num = 1;
	while(read(fd, buf, 1) > 0)
	{
		if ((((line == last_l || line == 1) && char_num != last_c + 1) 
			|| char_num == 1 || char_num == last_c) && *buf != '1')
		{
			printf("%d %d",line, char_num);
			free(buf);
			return (0);
		}
		if (*buf == '\n')
		{
			char_num = 1;
			line++;
		}
		else
			char_num++;
	}
	free(buf);
	return (1);
}

int	ft_parse_map(int argc, char **argv)
{
	int			fd;
	char		*buf;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (map_rectangle(fd) == 0)
		return (0);
	if (map_check_walls(argv[1]) == 0)
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
