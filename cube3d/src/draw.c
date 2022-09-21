/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 06:37:23 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/04 15:57:33 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_draw_wall1(t_map *tab, int y)
{
	if (tab->stuff.side == 1 && tab->stuff.raydir_y > 0)
	{
		tab->stuff.texty = (y * 2 - tab->height + tab->stuff.lineheight) *
		(tab->dst_e.height / 2) / tab->stuff.lineheight;
		tab->data.pix[y * tab->width + tab->stuff.x] =
		tab->dst_e.pix[(int)tab->stuff.texty * tab->dst_e.width +
		tab->stuff.texture_xe];
	}
	else if (tab->stuff.side == 1 && tab->stuff.raydir_y < 0)
	{
		tab->stuff.texty = (y * 2 - tab->height + tab->stuff.lineheight) *
		(tab->dst_w.height / 2) / tab->stuff.lineheight;
		tab->data.pix[y * tab->width + tab->stuff.x] =
		tab->dst_w.pix[(int)tab->stuff.texty * tab->dst_w.width +
		tab->stuff.texture_xw];
	}
}

void	ft_draw_wall(t_map *tab, int y)
{
	if (tab->stuff.side == 0 && tab->stuff.raydir_x < 0)
	{
		tab->stuff.texty = (y * 2 - tab->height + tab->stuff.lineheight) *
		(tab->dst_n.height / 2) / tab->stuff.lineheight;
		tab->data.pix[y * tab->width + tab->stuff.x] =
		tab->dst_n.pix[(int)tab->stuff.texty * tab->dst_n.width +
		tab->stuff.texture_xn];
	}
	else if (tab->stuff.side == 0 && tab->stuff.raydir_x > 0)
	{
		tab->stuff.texty = (y * 2 - tab->height + tab->stuff.lineheight) *
		(tab->dst_s.height / 2) / tab->stuff.lineheight;
		tab->data.pix[y * tab->width + tab->stuff.x] =
		tab->dst_s.pix[(int)tab->stuff.texty * tab->dst_s.width +
		tab->stuff.texture_xs];
	}
	else
		ft_draw_wall1(tab, y);
}

void	display_ray_gun(t_map *tab)
{
	int j;

	j = tab->height / 2 - 25;
	if (tab->stuff.x >= (tab->width / 2) - 1 && tab->stuff.x
			<= (tab->width / 2) + 1)
	{
		while (j <= tab->height / 2 + 25)
		{
			tab->data.pix[j * tab->width + tab->stuff.x] = 0xff0000;
			j++;
		}
	}
	j = tab->height / 2 - 1;
	if (tab->stuff.x >= (tab->width / 2) - 25 && tab->stuff.x <=
			(tab->width / 2) + 25)
	{
		while (j <= tab->height / 2 + 1)
		{
			tab->data.pix[j * tab->width + tab->stuff.x] = 0xff0000;
			j++;
		}
	}
}

void	ft_draw(t_map *tab)
{
	int y;

	y = -1;
	tab->stuff.start = -tab->stuff.lineheight / 2 + tab->height / 2;
	if (tab->stuff.start < 0)
		tab->stuff.start = 0;
	tab->stuff.end = tab->stuff.lineheight / 2 + tab->height / 2;
	if (tab->stuff.end >= tab->height)
		tab->stuff.end = tab->height - 1;
	exact_hit_pos(tab);
	while (++y < tab->stuff.start)
		tab->data.pix[y * tab->width + tab->stuff.x] = tab->rgb.skyhex;
	if (tab->stuff.texty < 50)
		tab->stuff.texty = 51;
	while (y < tab->stuff.end)
	{
		ft_draw_wall(tab, y);
		y++;
	}
	if (tab->stuff.end < 0)
		tab->stuff.end = 0;
	y = tab->stuff.end - 1;
	while (++y < tab->height)
		tab->data.pix[y * tab->width + tab->stuff.x] = tab->rgb.groundhex;
	tab->sp.zbuffer[tab->stuff.x] = tab->stuff.walldist;
}
