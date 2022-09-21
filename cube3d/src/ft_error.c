/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:58:40 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 18:19:22 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		map_error1(t_map *tab, int i, int j)
{
	if (j == 0 && (tab->map[i][j] == '0' || tab->map[i][j] == '2'))
		return (1);
	if (((tab->map[i][j] == '0' || tab->map[i][j] == '2')
	&& tab->map[i][j] != '\0') && (tab->map[i][j + 1] == ' ' ||
	tab->map[i][j + 1] == '\0'))
		return (1);
	if (((tab->map[i][j] == '0' || tab->map[i][j] == '2')
	&& j > 0) && (tab->map[i][j - 1] == ' '
	|| tab->map[i][j - 1] == '\0'))
		return (1);
	if (((tab->map[i][j] == '0' || tab->map[i][j] == '2')
	&& tab->map[i] != 0) &&
	(tab->map[i + 1][j] == ' ' || tab->map[i + 1][j] == '\0'))
		return (1);
	if (((tab->map[i][j] == '0' || tab->map[i][j] == '2')
	&& i > 0) && (tab->map[i - 1][j] == ' '
	|| tab->map[i - 1][j] == '\0'))
		return (1);
	return (0);
}

int		map_error(t_map *tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (tab->map[0][++j] != '\0')
		if (tab->map[0][j] == '0' || tab->map[0][j] == '2')
			return (1);
	j = -1;
	while (tab->map[++i] != 0)
		;
	while (tab->map[i - 1][++j])
		if (tab->map[i - 1][j] == '0' || tab->map[i - 1][j] == '2')
			return (1);
	if (checkspawn(tab) == 1)
		return (1);
	return (0);
}

int		check_map(t_map *tab)
{
	int i;
	int j;

	i = -1;
	while (tab->map[++i] != 0)
	{
		j = -1;
		while (tab->map[i][++j])
			if (map_error1(tab, i, j) == 1)
				return (1);
	}
	i = -1;
	while (tab->map[++i])
	{
		j = -1;
		while (tab->map[i][++j])
			if (tab->map[i][j] != '0' && tab->map[i][j] != '1'
			&& tab->map[i][j] != ' ' && tab->map[i][j] != '2' &&
			tab->map[i][j] != 'N' && tab->map[i][j] != 'E' &&
			tab->map[i][j] != 'W' && tab->map[i][j] != 'S')
				return (1);
	}
	if (map_error(tab) == 1)
		return (1);
	return (0);
}

int		check_rgb(t_map *tab)
{
	if (tab->width < 0 || tab->height < 0)
		return (2);
	if (tab->rgb.g_b > 255 || tab->rgb.g_g > 255 || tab->rgb.g_r > 255 ||
			tab->rgb.s_b > 255 || tab->rgb.s_g > 255 || tab->rgb.s_r > 255)
		return (1);
	if (tab->rgb.g_b < 0 || tab->rgb.g_g < 0 || tab->rgb.g_r < 0 ||
			tab->rgb.s_b < 0 || tab->rgb.s_g < 0 || tab->rgb.s_r < 0)
		return (1);
	return (0);
}

int		ft_check_path(t_map *tab)
{
	int fd;

	fd = open(tab->pathea, O_RDONLY);
	if (fd <= 0)
		return (1);
	fd = open(tab->pathno, O_RDONLY);
	if (fd <= 0)
		return (1);
	fd = open(tab->pathso, O_RDONLY);
	if (fd <= 0)
		return (1);
	fd = open(tab->pathsprite, O_RDONLY);
	if (fd <= 0)
		return (1);
	fd = open(tab->pathwe, O_RDONLY);
	if (fd <= 0)
		return (1);
	return (0);
}
