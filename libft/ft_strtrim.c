/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:21:01 by elbouju           #+#    #+#             */
/*   Updated: 2019/10/28 13:00:08 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			search(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int len;

	if (!s1 || !set)
		return (NULL);
	while (search(*s1, set) == 1)
		++s1;
	len = ft_strlen(s1);
	while (len && (search(s1[len - 1], set) == 1))
		--len;
	if (len == 0)
		return (ft_strdup("\0"));
	return (ft_substr(s1, 0, len));
}
