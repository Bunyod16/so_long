/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:02:02 by bunyodshams       #+#    #+#             */
/*   Updated: 2021/12/03 00:36:50 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strlast(int n, char *str)
{
    int len;
    int i;

    len = ft_strlen(str);
    if (len > n)
        return (NULL);
    i = len - n;
    while (i--)
        ++str;
    return (str);
}