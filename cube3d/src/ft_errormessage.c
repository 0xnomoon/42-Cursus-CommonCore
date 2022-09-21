/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormessage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:42:56 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 17:20:19 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		check_mainmapfile(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
	{
		write(1, "\n\033[31m(ERROR) File Error\n\n", 26);
		write(1, "\033[33m-Verify the path hhhh\n\n", 32);
		return (1);
	}
	if (str[ft_strlen(str) - 1] == 'b' && str[ft_strlen(str) - 2] == 'u'
			&& str[ft_strlen(str) - 3] == 'c' && str[ft_strlen(str) - 4] == '.')
		return (0);
	write(1, "\n\033[31m(ERROR) File Error\n\n", 26);
	write(1, "\033[33m-Be sure the file is a .cub, common wth is wrong", 54);
	write(1, "with you\n\n", 10);
	return (1);
}

int		checkfc(t_map *tab)
{
	if (tab->ground == NULL)
	{
		write(1, "\n\033[31m(ERROR) ground Error\n\n", 28);
		return (1);
	}
	if (tab->skybox == NULL)
	{
		write(1, "\n\033[31m(ERROR) skybox Error\n\n", 28);
		return (1);
	}
	if (tab->rs == NULL)
	{
		write(1, "\n\033[31m(ERROR) Resolution Error\n\n", 32);
		return (1);
	}
	ft_rgbground(tab);
	return (0);
}

int		ft_error1(t_map *tab)
{
	if (check_map(tab) == 1)
	{
		write(1, "\n\033[31m(ERROR) Map Char Error\n\n", 30);
		write(1, "\033[33m-Check if there is only [N,S,E,W,1,0,2] in", 48);
		write(1, "with you\n\n", 9);
		return (1);
	}
	if (check_rgb(tab) == 1)
	{
		write(1, "\n\033[31m(ERROR) RGB Error\n\n", 25);
		write(1, "\033[33m-Be sure all the RGB values are > 0 && <", 45);
		write(1, " 256\n\n", 6);
		return (1);
	}
	else if (check_rgb(tab) == 2)
	{
		write(1, "\n\033[31m(ERROR) RGB Error\n\n", 25);
		write(1, "\033[33m-Be sure res > 0\n\n", 22);
		return (1);
	}
	return (0);
}

int		ft_error(t_map *tab)
{
	if (map_error(tab) == 1)
	{
		write(1, "\n\033[31m(ERROR) Map Error\n\n", 25);
		write(1, "\033[33m-Check if the map is well surounded by '1'\n\n", 48);
		write(1, "\033[33m-or spawn error\n", 21);
		return (1);
	}
	if (ft_check_path(tab) == 1)
	{
		write(1, "\n\033[31m(ERROR) Texture Path Error\n\n", 34);
		write(1, "\033[33m-Check if all the texture path in the .cub file", 52);
		write(1, "are existing\n\n", 14);
		return (1);
	}
	if (checkfc(tab) == 1 || ft_error1(tab) == 1)
		return (1);
	else
		return (0);
}
