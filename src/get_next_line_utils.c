/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:41:23 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/12/02 23:41:23 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	gnl_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

int	gnl_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	if (!s)
		return (i);
	while (s[++i] != '\0')
		if (s[i] == c)
			return (i);
	return (-1);
}

char	*gnl_strdup(const char *s1)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ret[i] = *s1;
		s1++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char			*string;
	unsigned int	i;

	if (!s1)
		return (NULL);
	if (!gnl_strlen(s1) && !gnl_strlen(s2))
		return (gnl_strdup(""));
	string = (char *)malloc(sizeof(char)
			* (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!string)
		return (NULL);
	string[(gnl_strlen(s1) + gnl_strlen(s2))] = 0;
	i = 0;
	while (*s1)
		string[i++] = *s1++;
	while (*s2)
		string[i++] = *s2++;
	return (string);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*src;
	size_t	i;

	ret = malloc(len + 1);
	if (!ret)
		return (0);
	src = (char *)s + start;
	i = 0;
	while (*src && i < len)
		ret[i++] = *src++;
	ret[i] = 0;
	return (ret);
}
