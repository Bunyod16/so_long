/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:41:38 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/12/02 23:41:38 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*gnl_cut(char **builder)
{
	char	*line;
	char	*temp;

	if (!*builder)
		return (NULL);
	if (gnl_strchr(*builder, '\n') == -1)
	{
		line = gnl_substr(*builder, 0, gnl_strlen(*builder) + 1);
		free (*builder);
		*builder = NULL;
	}
	else
	{
		temp = *builder;
		line = gnl_substr(*builder, 0, gnl_strchr(*builder, '\n') + 1);
		*builder = gnl_substr(*builder, gnl_strchr(*builder, '\n') + 1,
				gnl_strlen(*builder) - gnl_strlen(line));
		free(temp);
	}
	return (line);
}

void	process(int fd, char **builder)
{
	int		i;
	char	*line;
	char	*buf;

	if (gnl_strchr(*builder, '\n') >= 0)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = 0;
		if (!*builder)
			*builder = gnl_substr(buf, 0, gnl_strlen(buf) + 1);
		else
		{
			line = *builder;
			*builder = gnl_strjoin(*builder, buf);
			free(line);
		}
		if (gnl_strchr(buf, '\n') >= 0)
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	static char	*builder = NULL;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, builder, 0) == -1)
		return (NULL);
	if (gnl_strchr(builder, '\n') == -1 || !*builder)
		process(fd, &builder);
	return (gnl_cut(&builder));
}
