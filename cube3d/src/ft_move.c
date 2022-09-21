/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:51:32 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/04 15:59:45 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_moverl(t_map *tab)
{
	if (tab->key.mover == 1)
	{
		if (tab->map[(int)(tab->fov.posx + tab->fov.planex * tab->stuff.speed)]
		[(int)tab->fov.posy] == '0')
			tab->fov.posx += tab->fov.planex * tab->stuff.speed;
		if (tab->map[(int)tab->fov.posx][(int)(tab->fov.posy + tab->fov.planey
		* tab->stuff.speed)] == '0')
			tab->fov.posy += tab->fov.planey * tab->stuff.speed;
	}
	if (tab->key.movel == 1)
	{
		if (tab->map[(int)(tab->fov.posx - tab->fov.planex * tab->stuff.speed)]
		[(int)tab->fov.posy] == '0')
			tab->fov.posx -= tab->fov.planex * tab->stuff.speed;
		if (tab->map[(int)tab->fov.posx][(int)(tab->fov.posy -
		tab->fov.planey * tab->stuff.speed)] == '0')
			tab->fov.posy -= tab->fov.planey * tab->stuff.speed;
	}
}

void	ft_rotatel(t_map *tab)
{
	if (tab->key.rotl == 1)
	{
		tab->fov.olddirx = tab->fov.dirx;
		tab->fov.dirx = tab->fov.dirx * cos(tab->stuff.rotspeed) -
		tab->fov.diry * sin(tab->stuff.rotspeed);
		tab->fov.diry = tab->fov.olddirx * sin(tab->stuff.rotspeed) +
		tab->fov.diry * cos(tab->stuff.rotspeed);
		tab->stuff.oldplanex = tab->fov.planex;
		tab->fov.planex = tab->fov.planex * cos(tab->stuff.rotspeed) -
		tab->fov.planey * sin(tab->stuff.rotspeed);
		tab->fov.planey = tab->stuff.oldplanex * sin(tab->stuff.rotspeed) +
		tab->fov.planey * cos(tab->stuff.rotspeed);
	}
}

void	ft_rotate(t_map *tab)
{
	if (tab->key.rotr == 1)
	{
		tab->fov.olddirx = tab->fov.dirx;
		tab->fov.dirx = tab->fov.dirx * cos(-tab->stuff.rotspeed) -
		tab->fov.diry * sin(-tab->stuff.rotspeed);
		tab->fov.diry = tab->fov.olddirx * sin(-tab->stuff.rotspeed) +
		tab->fov.diry * cos(-tab->stuff.rotspeed);
		tab->stuff.oldplanex = tab->fov.planex;
		tab->fov.planex = tab->fov.planex * cos(-tab->stuff.rotspeed) -
		tab->fov.planey * sin(-tab->stuff.rotspeed);
		tab->fov.planey = tab->stuff.oldplanex * sin(-tab->stuff.rotspeed) +
		tab->fov.planey * cos(-tab->stuff.rotspeed);
	}
	ft_rotatel(tab);
}

void	ft_move(t_map *tab)
{
	if (tab->key.sprint == 1)
		tab->stuff.speed = 0.035;
	else
		tab->stuff.speed = 0.1;
	if (tab->key.front == 1)
	{
		if (tab->map[(int)(tab->fov.posx + tab->fov.dirx * tab->stuff.speed)]
		[(int)(tab->fov.posy)] == '0')
			tab->fov.posx += tab->fov.dirx * tab->stuff.speed;
		if (tab->map[(int)(tab->fov.posx)][(int)(tab->fov.posy +
		tab->fov.diry * tab->stuff.speed)] == '0')
			tab->fov.posy += tab->fov.diry * tab->stuff.speed;
	}
	if (tab->key.back == 1)
	{
		if (tab->map[(int)(tab->fov.posx - tab->fov.dirx * tab->stuff.speed)]
		[(int)tab->fov.posy] == '0')
			tab->fov.posx -= tab->fov.dirx * tab->stuff.speed;
		if (tab->map[(int)tab->fov.posx][(int)(tab->fov.posy -
		tab->fov.diry * tab->stuff.speed)] == '0')
			tab->fov.posy -= tab->fov.diry * tab->stuff.speed;
	}
	ft_rotate(tab);
	ft_moverl(tab);
}
