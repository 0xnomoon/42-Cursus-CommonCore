/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:58:56 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/09 19:32:21 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		uselessp1(t_map *tab, int x, int y)
{
	if ((x > (int)ft_strlen(tab->map[y - 1]) && y > 0) ||
	(x > (int)ft_strlen(tab->map[y + 1]) && tab->map[y] != 0
	&& tab->map[y + 1] != 0))
		return (1);
	return (0);
}
