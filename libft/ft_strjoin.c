/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:12:30 by elbouju           #+#    #+#             */
/*   Updated: 2019/10/28 12:58:11 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
