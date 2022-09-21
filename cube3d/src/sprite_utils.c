/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:54:28 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 12:31:22 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	count_sprite(t_map *tab)
{
	int x;
	int y;
	int si;

	x = 0;
	y = 0;
	si = 0;
	while (tab->map[x] != 0)
	{
		y = 0;
		while (tab->map[x][y])
		{
			if (tab->map[x][y] == '2')
			{
				tab->sp.sp[si][0] = (double)x;
				tab->sp.sp[si][1] = (double)y;
				tab->sp.sp[si++][2] = 0;
			}
			y++;
		}
		x++;
	}
}

int		sp_malloc(t_map *tab)
{
	int h;

	h = 0;
	while (*tab->mapcpy++)
		if (*tab->mapcpy == '2')
			tab->sp.nbsp++;
	if (!(tab->sp.sp = (double **)malloc(sizeof(double *) *
	(tab->sp.nbsp + 1))))
		return (0);
	while (h <= tab->sp.nbsp)
		if (!(tab->sp.sp[h++] = (double *)malloc(sizeof(double) * (3))))
			return (0);
	count_sprite(tab);
	return (0);
}

void	ft_sortsp(t_map *tab)
{
	int		i;
	double	spritedist;
	double	tempx;
	double	tempy;

	i = -1;
	while (++i < tab->sp.nbsp && tab->sp.nbsp > 1)
	{
		spritedist = ((tab->fov.posx - tab->sp.sp[i][0]) * (tab->fov.posx -
		tab->sp.sp[i][0]) + (tab->fov.posy - tab->sp.sp[i][1]) *
		(tab->fov.posy - tab->sp.sp[i][1]));
		if (spritedist < ((tab->fov.posx - tab->sp.sp[i + 1][0]) *
		(tab->fov.posx - tab->sp.sp[i + 1][0]) + (tab->fov.posy -
		tab->sp.sp[i + 1][1]) * (tab->fov.posy - tab->sp.sp[i + 1][1]))
		&& i + 1 < tab->sp.nbsp)
		{
			tempx = tab->sp.sp[i][0];
			tempy = tab->sp.sp[i][1];
			tab->sp.sp[i][0] = tab->sp.sp[i + 1][0];
			tab->sp.sp[i][1] = tab->sp.sp[i + 1][1];
			tab->sp.sp[i + 1][0] = tempx;
			tab->sp.sp[i + 1][1] = tempy;
			i = 0;
		}
	}
}
