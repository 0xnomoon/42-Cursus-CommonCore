/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:39:55 by elbouju           #+#    #+#             */
/*   Updated: 2019/10/23 18:32:08 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_charfinder(char c, char find)
{
	if (c == find)
		return (0);
	return (1);
}

static int		ft_countword(char const *s, char find)
{
	int i;

	i = 0;
	while (*s)
	{
		while (ft_charfinder(*s, find) == 0 && *s)
			s++;
		if (*s != '\0')
			i++;
		while (ft_charfinder(*s, find) == 1 && *s != '\0')
			s++;
	}
	return (i);
}

static int		ft_cc(char const *s, char c)
{
	int i;

	i = 0;
	while (ft_charfinder(*s, c) != 0 && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		words;
	int		j;

	i = -1;
	if (!s)
		return (NULL);
	words = ft_countword(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++i < words)
	{
		j = 0;
		while (ft_charfinder(*s, c) == 0 && *s != '\0')
			s++;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (ft_cc(s, c) + 1))))
			return (NULL);
		while (*s != '\0' && ft_charfinder(*s, c) == 1)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
