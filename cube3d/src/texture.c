/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:00:40 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/04 16:02:00 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	get_texture_x_p1(t_map *tab)
{
	tab->stuff.texture_xe = (int)(tab->stuff.wallx * tab->dst_e.width);
	if (tab->stuff.side == 0 && tab->stuff.raydir_x > 0)
		tab->stuff.texture_xe = tab->dst_e.width - tab->stuff.texture_xe - 1;
	if (tab->stuff.side == 1 && tab->stuff.raydir_y < 0)
		tab->stuff.texture_xe = tab->dst_e.width - tab->stuff.texture_xe - 1;
	tab->stuff.texture_xsp = (int)(tab->stuff.wallx * tab->dst_n.width);
	if (tab->stuff.side == 0 && tab->stuff.raydir_x > 0)
		tab->stuff.texture_xsp = tab->dst_sp.width - tab->stuff.texture_xsp - 1;
	if (tab->stuff.side == 1 && tab->stuff.raydir_y < 0)
		tab->stuff.texture_xsp = tab->dst_sp.width - tab->stuff.texture_xsp - 1;
}

void	get_texture_x(t_map *tab)
{
	tab->stuff.texture_xn = (int)(tab->stuff.wallx * tab->dst_n.width);
	if (tab->stuff.side == 0 && tab->stuff.raydir_x > 0)
		tab->stuff.texture_xn = tab->dst_n.width - tab->stuff.texture_xn - 1;
	if (tab->stuff.side == 1 && tab->stuff.raydir_y < 0)
		tab->stuff.texture_xn = tab->dst_n.width - tab->stuff.texture_xn - 1;
	tab->stuff.texture_xs = (int)(tab->stuff.wallx * tab->dst_s.width);
	if (tab->stuff.side == 0 && tab->stuff.raydir_x > 0)
		tab->stuff.texture_xs = tab->dst_s.width - tab->stuff.texture_xs - 1;
	if (tab->stuff.side == 1 && tab->stuff.raydir_y < 0)
		tab->stuff.texture_xs = tab->dst_s.width - tab->stuff.texture_xs - 1;
	tab->stuff.texture_xw = (int)(tab->stuff.wallx * tab->dst_w.width);
	if (tab->stuff.side == 0 && tab->stuff.raydir_x > 0)
		tab->stuff.texture_xw = tab->dst_w.width - tab->stuff.texture_xw - 1;
	if (tab->stuff.side == 1 && tab->stuff.raydir_y < 0)
		tab->stuff.texture_xw = tab->dst_w.width - tab->stuff.texture_xw - 1;
	get_texture_x_p1(tab);
}

void	get_texture_p1(t_map *tab, t_texture *src)
{
	tab->dst_w.smallval = (tab->dst_w.width <= tab->dst_w.height ?
	tab->dst_w.width : tab->dst_w.height);
	src->img = mlx_xpm_file_to_image(tab->data.ptr, tab->pathea,
	&(tab->dst_e.width), &(tab->dst_e.height));
	tab->dst_e.pix = (int *)mlx_get_data_addr(src->img, &src->bpp,
	&src->size, &src->endian);
	tab->dst_e.img = src->img;
	tab->dst_e.smallval = (tab->dst_e.width <= tab->dst_e.height ?
	tab->dst_e.width : tab->dst_e.height);
	src->img = mlx_xpm_file_to_image(tab->data.ptr, tab->pathsprite,
	&(tab->dst_sp.width), &(tab->dst_sp.height));
	tab->dst_sp.pix = (int *)mlx_get_data_addr(src->img, &src->bpp,
	&src->size, &src->endian);
	tab->dst_sp.img = src->img;
	tab->dst_sp.smallval = (tab->dst_sp.width <= tab->dst_sp.height ?
	tab->dst_sp.width : tab->dst_sp.height);
	free(src);
}

void	get_texture(t_map *tab)
{
	t_texture *src;

	if (!(src = (t_texture*)malloc(sizeof(t_texture))))
		return ;
	src->img = mlx_xpm_file_to_image(tab->data.ptr, tab->pathno,
	&(tab->dst_n.width), &(tab->dst_n.height));
	tab->dst_n.pix = (int *)mlx_get_data_addr(src->img, &src->bpp,
	&src->size, &src->endian);
	tab->dst_n.img = src->img;
	tab->dst_n.smallval = (tab->dst_n.width <= tab->dst_n.height ?
	tab->dst_n.width : tab->dst_n.height);
	src->img = mlx_xpm_file_to_image(tab->data.ptr, tab->pathso,
	&(tab->dst_s.width), &(tab->dst_s.height));
	tab->dst_s.pix = (int *)mlx_get_data_addr(src->img, &src->bpp,
	&src->size, &src->endian);
	tab->dst_s.img = src->img;
	tab->dst_s.smallval = (tab->dst_s.width <= tab->dst_s.height ?
	tab->dst_s.width : tab->dst_s.height);
	src->img = mlx_xpm_file_to_image(tab->data.ptr, tab->pathwe,
	&(tab->dst_w.width), &(tab->dst_w.height));
	tab->dst_w.pix = (int *)mlx_get_data_addr(src->img, &src->bpp,
	&src->size, &src->endian);
	tab->dst_w.img = src->img;
	get_texture_p1(tab, src);
}
