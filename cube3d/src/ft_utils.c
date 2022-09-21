/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:26:39 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/04 15:58:16 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		is_loopneeded(t_map *tab)
{
	if (tab->firstaff-- == 1 || tab->key.rotl || tab->key.rotr
			|| tab->key.front || tab->key.back || tab->key.movel
			|| tab->key.mover)
		return (1);
	return (0);
}

int		whilenb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '0' && str[i] < '9')
			break ;
		i++;
	}
	return (i);
}

int		whilespace(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return (i);
}

int		check_screenshot(char *str, t_map *tab)
{
	if (ft_strlen(str) == 6)
	{
		if (str[0] == '-' && str[1] == '-' && str[2] == 's' && str[3] == 'a'
		&& str[4] == 'v' && str[5] == 'e')
		{
			tab->screenshot = 1;
			return (1);
		}
	}
	return (0);
}

int		ft_atoi(const char *str)
{
	int i;
	int neg;

	neg = 1;
	i = 0;
	while (*str != '\0' && (*str == '\t' || *str == '\n' || *str == '\r' ||
				*str == '\v' || *str == '\f' || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (i * neg);
}
