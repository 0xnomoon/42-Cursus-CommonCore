/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:20:42 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/09 19:31:04 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		map_error2(t_map *tab, int i, int j)
{
	if (j == 0 && (tab->map[i][j] == 'N' || tab->map[i][j] == 'E'
	|| tab->map[i][j] == 'W' || tab->map[i][j] == 'S'))
		return (1);
	if (((tab->map[i][j] == 'N' || tab->map[i][j] == 'E'
	|| tab->map[i][j] == 'W' || tab->map[i][j] == 'S') &&
	tab->map[i][j] != '\0') &&
	(tab->map[i][j + 1] == ' ' || tab->map[i][j + 1] == '\0'))
		return (1);
	if (((tab->map[i][j] == 'N' || tab->map[i][j] == 'E' ||
	tab->map[i][j] == 'W' || tab->map[i][j] == 'S') && j > 0) &&
	(tab->map[i][j - 1] == ' '
	|| tab->map[i][j - 1] == '\0'))
		return (1);
	if (((tab->map[i][j] == 'N' || tab->map[i][j] == 'E' ||
	tab->map[i][j] == 'W' || tab->map[i][j] == 'S') && tab->map[i] != 0) &&
	(tab->map[i + 1][j] == ' ' || tab->map[i + 1][j] == '\0'))
		return (1);
	if (((tab->map[i][j] == 'N' || tab->map[i][j] == 'E' ||
	tab->map[i][j] == 'W' || tab->map[i][j] == 'S') && i > 0) &&
	(tab->map[i - 1][j] == ' '
	|| tab->map[i - 1][j] == '\0'))
		return (1);
	return (0);
}

int		map_error5(t_map *tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (tab->map[0][++j] != '\0')
		if (tab->map[0][j] == 'N' || tab->map[0][j] == 'E' ||
		tab->map[0][j] == 'W' || tab->map[0][j] == 'S')
			return (1);
	while (tab->map[++i] != 0)
		;
	j = -1;
	while (tab->map[i - 1][++j])
		if (tab->map[i - 1][j] == 'N' || tab->map[i - 1][j] == 'E' ||
		tab->map[i - 1][j] == 'W' || tab->map[i - 1][j] == 'S')
			return (1);
	return (0);
}

int		checkspawn1(t_map *tab)
{
	int i;
	int j;

	i = -1;
	while (tab->map[++i + 1] != 0)
	{
		j = -1;
		while (tab->map[i][++j])
			if (map_error2(tab, i, j) == 1)
				return (1);
	}
	if (map_error5(tab) == 1)
		return (1);
	return (0);
}

int		useless(t_map *tab, int nb)
{
	if (nb < 1)
		return (1);
	if (checkspawn1(tab) == 1)
		return (1);
	return (0);
}

int		checkspawn(t_map *tab)
{
	int y;
	int x;
	int nb;

	nb = 0;
	y = -1;
	while (tab->map[++y])
	{
		x = -1;
		while (tab->map[y][++x])
		{
			if (tab->map[y][x] == 'N' || tab->map[y][x] == 'S' ||
			tab->map[y][x] == 'E' || tab->map[y][x] == 'W')
			{
				if (uselessp1(tab, x, y) == 1)
					return (1);
				nb += 1;
				if (nb > 1)
					return (1);
			}
		}
	}
	if (useless(tab, nb) == 1)
		return (1);
	return (0);
}
