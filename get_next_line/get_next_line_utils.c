/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:34:33 by elbouju           #+#    #+#             */
/*   Updated: 2019/11/06 18:14:03 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char		*sdupfr(char *s1, size_t n)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	dest[i] = '\0';
	n == 1 ? free(s1) : 1;
	return (dest);
}

char		*ft_sjoin_free(char const *dst, char const *src, size_t n)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!dst || !src)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	if (!(new = (char *)malloc(sizeof(char) *
					(ft_strlen(src) + ft_strlen(dst) + 1))))
		return (NULL);
	while (dst[i] || src[j])
	{
		if (dst[i])
			new[k++] = dst[i++];
		else
			new[k++] = src[j++];
	}
	new[k] = '\0';
	n >= 1 ? free((void *)dst) : 1;
	n == 2 ? free((void *)src) : 1;
	return (new);
}

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
