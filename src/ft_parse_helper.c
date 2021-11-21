/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:32:24 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/21 03:28:45 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	max_chr(char *map)
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

int	max_ln(char *map)
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

void	set_zero(t_char_count *char_count)
{
	char_count->C = 0;
	char_count->E = 0;
	char_count->P = 0;

	return ;
}