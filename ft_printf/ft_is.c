/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:28:24 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:38:23 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_letter(char c)
{
	if (c != 'd' && c != 'u' && c != 'i' && c != 'x' && c != 'X' &&
			c != 'c' && c != 's' && c != 'p' && c != '%')
		return (1);
	else
		return (0);
}

void	ft_putzero(t_printf *s, int size)
{
	while (size-- && size > 0)
		ft_putchar('0', s);
}

void	ft_putspace(t_printf *s, int size)
{
	while (size-- && size > 0)
		ft_putchar(' ', s);
}

int		ft_passnum(char *str)
{
	int i;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}
