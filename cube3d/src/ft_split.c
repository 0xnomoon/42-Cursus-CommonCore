/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 10:38:57 by elbouju           #+#    #+#             */
/*   Updated: 2020/02/24 18:05:17 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		ft_find(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset && charset != '\0')
			return (1);
		charset++;
	}
	return (0);
}

int		count_word(char *str, char *charset)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (*str != '\0')
	{
		while (ft_find(*str, charset) == 1 && *str != '\0')
			str++;
		if (*str != '\0')
			j++;
		while (ft_find(*str, charset) != 1 && *str != '\0')
			str++;
	}
	return (j);
}

int		cc(char *str, char *charset)
{
	int i;

	i = 0;
	while (ft_find(*str, charset) != 1 && *str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		words;
	int		j;

	i = -1;
	words = count_word(str, charset);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++i < words)
	{
		j = 0;
		while (ft_find(*str, charset) == 1 && *str != '\0')
			str++;
		if (!(tab[i] = (char *)malloc(sizeof(char) * ((cc(str, charset)) + 1))))
			return (NULL);
		while (*str != '\0' && ft_find(*str, charset) == 0)
		{
			tab[i][j++] = *str++;
		}
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
