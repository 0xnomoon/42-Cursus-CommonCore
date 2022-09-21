/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:34:33 by elbouju           #+#    #+#             */
/*   Updated: 2020/02/24 18:59:11 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*sdupfr(char *s1, size_t n)
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

char	*ft_sjoin_free(char const *dst, char const *src, size_t n)
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

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	int		y;
	char	*str;

	y = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (s1[y] != '\0')
		str[k++] = s1[y++];
	y = 0;
	while (s2[y] != '\0')
		str[k++] = s2[y++];
	str[k] = '\0';
	return (str);
}
