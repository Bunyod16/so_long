/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:32:29 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/11/21 05:11:48 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#define BUFFER_SIZE 1

typedef struct  s_char_count
{
    int C;
    int E;
    int P;
}   t_char_count;

int ft_parse_map(int argc, char **argv);
int	max_chr(char *map);
int	max_ln(char *map);
void	set_zero(t_char_count *char_count);
char	*get_next_line(int fd);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(const char *s1);
size_t	gnl_strlen(const char *s);
int	gnl_strchr(const char *s, int c);

# endif