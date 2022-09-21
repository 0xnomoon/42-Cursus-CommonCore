/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:21:47 by elbouju           #+#    #+#             */
/*   Updated: 2020/02/28 13:36:27 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_calcray(t_map *tab)
{
	tab->stuff.camerax = 2 * tab->stuff.x / (double)tab->width - 1;
	tab->stuff.raydir_x = tab->fov.dirx + tab->fov.planex * tab->stuff.camerax;
	tab->stuff.raydir_y = tab->fov.diry + tab->fov.planey * tab->stuff.camerax;
	tab->stuff.mapx = (int)tab->fov.posx;
	tab->stuff.mapy = (int)tab->fov.posy;
	tab->stuff.deltadistx = fabs(1 / tab->stuff.raydir_x);
	tab->stuff.deltadisty = fabs(1 / tab->stuff.raydir_y);
	tab->stuff.hit = 0;
	ft_calcstepside(tab);
}

void	ft_calcstepside(t_map *tab)
{
	if (tab->stuff.raydir_x < 0)
	{
		tab->stuff.stepx = -1;
		tab->stuff.sidedistx = (tab->fov.posx - tab->stuff.mapx) *
		tab->stuff.deltadistx;
	}
	else
	{
		tab->stuff.stepx = 1;
		tab->stuff.sidedistx = (tab->stuff.mapx + 1.0 - tab->fov.posx) *
		tab->stuff.deltadistx;
	}
	if (tab->stuff.raydir_y < 0)
	{
		tab->stuff.stepy = -1;
		tab->stuff.sidedisty = (tab->fov.posy - tab->stuff.mapy) *
		tab->stuff.deltadisty;
	}
	else
	{
		tab->stuff.stepy = 1;
		tab->stuff.sidedisty = (tab->stuff.mapy + 1.0 - tab->fov.posy) *
		tab->stuff.deltadisty;
	}
	ft_hit(tab);
}

void	exact_hit_pos(t_map *tab)
{
	if (tab->stuff.side == 0)
		tab->stuff.wallx = tab->fov.posy + tab->stuff.walldist
		* tab->stuff.raydir_y;
	else
		tab->stuff.wallx = tab->fov.posx + tab->stuff.walldist
		* tab->stuff.raydir_x;
	tab->stuff.wallx -= (int)tab->stuff.wallx;
}

void	ft_hit(t_map *tab)
{
	while (tab->stuff.hit == 0)
	{
		if (tab->stuff.sidedistx < tab->stuff.sidedisty)
		{
			tab->stuff.sidedistx += tab->stuff.deltadistx;
			tab->stuff.mapx += tab->stuff.stepx;
			tab->stuff.side = 0;
		}
		else
		{
			tab->stuff.sidedisty += tab->stuff.deltadisty;
			tab->stuff.mapy += tab->stuff.stepy;
			tab->stuff.side = 1;
		}
		if (tab->map[tab->stuff.mapx][tab->stuff.mapy] == '1')
			tab->stuff.hit = 1;
	}
	ft_distance(tab);
	get_texture_x(tab);
	ft_draw(tab);
}

void	ft_distance(t_map *tab)
{
	if (tab->stuff.side == 0)
		tab->stuff.walldist = fabs((tab->stuff.mapx - tab->fov.posx +
		(1 - tab->stuff.stepx) / 2) / tab->stuff.raydir_x);
	else
		tab->stuff.walldist = fabs((tab->stuff.mapy - tab->fov.posy +
		(1 - tab->stuff.stepy) / 2) / tab->stuff.raydir_y);
	tab->stuff.lineheight = (int)(tab->height / tab->stuff.walldist);
}
