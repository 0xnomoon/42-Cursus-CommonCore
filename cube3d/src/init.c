/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 06:17:56 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 15:25:35 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_spawndirone(t_map *tab, char c)
{
	if (c == 'W')
	{
		tab->fov.dirx = 0;
		tab->fov.diry = -1;
		tab->fov.planex = -0.66;
		tab->fov.planey = 0;
	}
	if (c == 'E')
	{
		tab->fov.dirx = 0;
		tab->fov.diry = 1;
		tab->fov.planex = 0.66;
		tab->fov.planey = 0;
	}
}

void	ft_spwandir(t_map *tab, char c)
{
	if (c == 'N')
	{
		tab->fov.dirx = -1;
		tab->fov.diry = 0;
		tab->fov.planex = 0;
		tab->fov.planey = 0.66;
	}
	if (c == 'S')
	{
		tab->fov.dirx = 1;
		tab->fov.diry = 0;
		tab->fov.planex = 0;
		tab->fov.planey = -0.66;
	}
	ft_spawndirone(tab, c);
}

int		init_calc(t_map *tab, int y, int x)
{
	if (!(tab->sp.zbuffer = (double *)malloc(sizeof(double) *
	(tab->width + 1))))
		return (0);
	tab->sp.zbuffer[tab->width] = '\0';
	tab->fov.orientation = tab->map[y][x];
	tab->fov.posx = y + 0.5;
	tab->fov.posy = x + 0.5;
	ft_spwandir(tab, tab->map[y][x]);
	tab->map[y][x] = '0';
	tab->stuff.speed = 0.1;
	tab->stuff.rotspeed = 0.03;
	return (0);
}

int		ft_initvar(t_map *tab)
{
	int y;
	int x;

	y = 0;
	sp_malloc(tab);
	while (tab->map[y] != 0)
	{
		x = 0;
		while (tab->map[y][x] && (tab->map[y][x] != 'N' && tab->map[y][x] != 'S'
		&& tab->map[y][x] != 'E' && tab->map[y][x] != 'W'))
			x++;
		if (tab->map[y][x] == 'N' || tab->map[y][x] == 'S' || tab->map[y][x] ==
		'E' || tab->map[y][x] == 'W')
			break ;
		y++;
	}
	init_calc(tab, y, x);
	return (0);
}
