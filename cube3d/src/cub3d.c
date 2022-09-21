/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 07:33:11 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 12:38:49 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		ft_loopgame(t_map *tab)
{
	tab->stuff.x = -1;
	if (is_loopneeded(tab) == 1)
	{
		ft_move(tab);
		while (++tab->stuff.x < tab->width)
		{
			ft_calcray(tab);
		}
		ft_sortsprite(tab);
		mlx_put_image_to_window(tab->data.ptr, tab->data.win,
				tab->data.img, 0, 0);
		mlx_string_put(tab->data.ptr, tab->data.win, 20, 20, 0,
				"[W] Forward / [S] Backward / [A] Left / [D] Right");
		mlx_string_put(tab->data.ptr, tab->data.win, 20, 50, 0,
				"[<-] Rotate left / [->] Rotate right");
		display_ray_gun(tab);
	}
	return (0);
}

int		initfree(t_map *tab)
{
	if (ft_error(tab) == 1)
	{
		free(tab);
		return (1);
	}
	ft_initvar(tab);
	ft_window(tab);
	free(tab->map);
	free(tab->sp.zbuffer);
	free((void *)tab->sp.sp);
	free(tab);
	return (0);
}

int		main(int ac, char **av)
{
	t_map	*tab;
	int		fd;

	if (check_mainmapfile(av[1]) == 1)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!(tab = (t_map*)malloc(sizeof(t_map))))
		return (-1);
	if (ac == 2 || (ac == 3 && check_screenshot(av[2], tab) == 1))
	{
		if (ft_parse(tab, fd) == 1)
			return (1);
		if (initfree(tab) == 1)
			return (1);
	}
	else
	{
		free(tab);
		write(1, "ERROR\n", 6);
	}
	return (0);
}
