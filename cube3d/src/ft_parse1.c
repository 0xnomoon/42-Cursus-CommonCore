/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:46:28 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 15:40:19 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	parseres(char *str, t_map *tab)
{
	int i;

	i = 0;
	if (str[0] == 'R' && tab->rs != NULL)
	{
		write(1, "\n\033[31m(ERROR) Double Path Error\n\n", 33);
		exit(0);
	}
	if (str[0] == 'R')
	{
		tab->rs = "r";
		i++;
		tab->width = ft_atoi(str + i);
		tab->width > 2560 ? tab->width = 2560 : tab->width;
		tab->width % 2 == 0 ? tab->width : tab->width++;
		while (str[i] == ' ')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		tab->height = ft_atoi(&str[i]);
		tab->height > 1440 ? tab->height = 1440 : tab->height;
		tab->height % 2 == 0 ? tab->height : tab->height++;
		free(str);
	}
}

void	parse_path_error(char *str, t_map *tab)
{
	if ((str[0] == 'N' && tab->pathno != NULL) ||
	(str[0] == 'S' && str[1] == 'O' && tab->pathso != NULL) ||
	(str[0] == 'W' && tab->pathwe != NULL) ||
	(str[0] == 'E' && tab->pathea != NULL) ||
	(str[0] == 'S' && str[1] == ' ' && tab->pathsprite != NULL) ||
	(str[0] == 'F' && tab->ground != NULL) ||
	(str[0] == 'C' && tab->skybox != NULL))
	{
		write(1, "\n\033[31m(ERROR) Double Path Error\n\n", 33);
		exit(0);
	}
}
