/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 04:07:23 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/04 15:59:18 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	sprite_calc(t_map *tab)
{
	tab->sp.spx = tab->sp.sp[tab->sp.i][0] - tab->fov.posx + 0.5;
	tab->sp.spy = tab->sp.sp[tab->sp.i][1] - tab->fov.posy + 0.5;
	tab->sp.indev = 1.0 / (tab->fov.planex * tab->fov.diry -
			tab->fov.dirx * tab->fov.planey);
	tab->sp.transformx = tab->sp.indev * (tab->fov.diry * tab->sp.spx -
			tab->fov.dirx * tab->sp.spy);
	tab->sp.transformy = tab->sp.indev * (-tab->fov.planey * tab->sp.spx +
			tab->fov.planex * tab->sp.spy);
	tab->sp.spsx = (int)((tab->width / 2) * (1 + tab->sp.transformx /
				tab->sp.transformy));
	tab->sp.sph = abs((int)(tab->height / tab->sp.transformy) / 1);
}

void	sprite_draw_calc(t_map *tab)
{
	tab->sp.drawstarty = -tab->sp.sph / 2 + tab->height / 2;
	if (tab->sp.drawstarty < 0)
		tab->sp.drawstarty = 0;
	tab->sp.drawendy = tab->sp.sph / 2 + tab->height / 2;
	if (tab->sp.drawendy >= tab->height)
		tab->sp.drawendy = tab->height - 1;
	tab->sp.spwidth = abs((int)(tab->height / tab->sp.transformy));
	tab->sp.drawstartx = -tab->sp.spwidth / 2 + tab->sp.spsx;
	if (tab->sp.drawstartx < 0)
		tab->sp.drawstartx = 0;
	tab->sp.drawendx = tab->sp.spwidth / 2 + tab->sp.spsx;
	if (tab->sp.drawendx >= tab->width)
		tab->sp.drawendx = tab->width - 1;
	tab->sp.stripe = tab->sp.drawstartx;
}

void	sprite_ray_draw(t_map *tab)
{
	int y;
	int d;
	int color;

	y = tab->sp.drawstarty;
	while (y < tab->sp.drawendy)
	{
		d = (y) * 256 - tab->height * 128 + tab->sp.sph * 128;
		tab->stuff.texty = ((d * tab->dst_sp.height) / tab->sp.sph) / 256;
		color = tab->dst_sp.pix[tab->dst_sp.width *
			(int)tab->stuff.texty + tab->stuff.textx];
		if ((color & 0xFFFFFF) != 0)
			tab->data.pix[y * tab->width + tab->sp.stripe] = color;
		y++;
	}
}

void	ft_sortsprite(t_map *tab)
{
	tab->sp.i = -1;
	ft_sortsp(tab);
	while (++tab->sp.i < tab->sp.nbsp)
	{
		sprite_calc(tab);
		sprite_draw_calc(tab);
		while (tab->sp.stripe < tab->sp.drawendx)
		{
			tab->stuff.textx = (int)((256 * (tab->sp.stripe - (-tab->sp.spwidth
			/ 2 + tab->sp.spsx)) * tab->dst_sp.width / tab->sp.spwidth) / 256);
			if (tab->sp.transformy > 0 && tab->sp.stripe > 0 && tab->sp.stripe <
			tab->width && tab->sp.transformy < tab->sp.zbuffer[tab->sp.stripe])
				sprite_ray_draw(tab);
			tab->sp.stripe++;
		}
	}
}
