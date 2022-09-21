/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 05:29:12 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 15:33:08 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_init_mlx(t_map *tab)
{
	int		lol;

	tab->firstaff = 1;
	tab->data.ptr = mlx_init();
	tab->data.win = mlx_new_window(tab->data.ptr, tab->width, tab->height,
	"cub3d");
	tab->data.img = mlx_new_image(tab->data.ptr, tab->width, tab->height);
	tab->data.pix = (int *)mlx_get_data_addr(tab->data.img, &lol, &lol, &lol);
	get_texture(tab);
}

void	ft_window(t_map *tab)
{
	ft_init_mlx(tab);
	if (tab->screenshot == 1)
	{
		create_screenshot(tab);
		exit(0);
	}
	mlx_hook(tab->data.win, 2, 0, key_press, tab);
	mlx_hook(tab->data.win, 3, 0, key_release, tab);
	mlx_hook(tab->data.win, 17, 0, ft_exit, tab);
	mlx_loop_hook(tab->data.ptr, ft_loopgame, tab);
	mlx_loop(tab->data.ptr);
}
