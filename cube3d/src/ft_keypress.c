/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:26:17 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/04 15:53:11 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		ft_exit(t_map *tab)
{
	free(tab);
	exit(0);
	return (0);
}

int		key_press(int keycode, t_map *tab)
{
	tab->key.rotl = (keycode == 123 ? 1 : tab->key.rotl);
	tab->key.rotr = (keycode == 124 ? 1 : tab->key.rotr);
	tab->key.front = (keycode == 13 ? 1 : tab->key.front);
	tab->key.back = (keycode == 1 ? 1 : tab->key.back);
	tab->key.movel = (keycode == 0 ? 1 : tab->key.movel);
	tab->key.mover = (keycode == 2 ? 1 : tab->key.mover);
	tab->key.sprint = (keycode == 257 ? 1 : tab->key.sprint);
	if (keycode == 53)
	{
		free(tab->map);
		mlx_destroy_window(tab->data.ptr, tab->data.win);
		exit(0);
	}
	return (0);
}

int		key_release(int keycode, t_map *tab)
{
	(keycode == 123 ? tab->key.rotl-- : 0);
	(keycode == 124 ? tab->key.rotr-- : 0);
	(keycode == 13 ? tab->key.front-- : 0);
	(keycode == 1 ? tab->key.back-- : 0);
	(keycode == 0 ? tab->key.movel-- : 0);
	(keycode == 2 ? tab->key.mover-- : 0);
	(keycode == 257 ? tab->key.sprint-- : 0);
	return (0);
}
