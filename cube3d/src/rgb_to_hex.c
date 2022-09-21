/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:51:54 by elbouju           #+#    #+#             */
/*   Updated: 2020/02/24 19:01:21 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_rgbsky(t_map *tab)
{
	int i;

	i = 0;
	tab->rgb.s_r = ft_atoi(tab->skybox);
	while (tab->skybox[i] && tab->skybox[i] >= '0' && tab->skybox[i] <= '9')
		i++;
	i++;
	tab->rgb.s_g = ft_atoi(&tab->skybox[i]);
	while (tab->skybox[i] && tab->skybox[i] >= '0' && tab->skybox[i] <= '9')
		i++;
	i++;
	tab->rgb.s_b = ft_atoi(&tab->skybox[i]);
	tab->rgb.skyhex = tab->rgb.s_b | tab->rgb.s_r << 16 | tab->rgb.s_g << 8;
	while (tab->skybox[i] && tab->skybox[i] >= '0' && tab->skybox[i] <= '9')
		i++;
	if (tab->skybox[i] != '\0')
	{
		printf("hhhhhhh\n");
		write(1, "\n\033[31m(ERROR) RGB Error\n\n", 25);
		exit(0);
	}
}

void	ft_rgbground(t_map *tab)
{
	int i;

	i = 0;
	tab->rgb.g_r = ft_atoi(tab->ground);
	while (tab->ground[i] && tab->ground[i] >= '0' && tab->ground[i] <= '9')
		i++;
	i++;
	tab->rgb.g_g = ft_atoi(&tab->ground[i]);
	while (tab->ground[i] && tab->ground[i] >= '0' && tab->ground[i] <= '9')
		i++;
	i++;
	tab->rgb.g_b = ft_atoi(&tab->ground[i]);
	tab->rgb.groundhex = tab->rgb.g_b | tab->rgb.g_r << 16 | tab->rgb.g_g << 8;
	while (tab->ground[i] && tab->ground[i] >= '0' && tab->ground[i] <= '9')
		i++;
	if (tab->ground[i] != '\0')
	{
		printf("hhhhhhh\n");
		write(1, "\n\033[31m(ERROR) RGB Error\n\n", 25);
		exit(0);
	}
	ft_rgbsky(tab);
}
