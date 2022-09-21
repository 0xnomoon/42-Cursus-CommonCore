/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:34:54 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:40:43 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_c(t_printf *s, char c)
{
	if (s->flag_minus == 1)
	{
		ft_putchar(c, s);
		ft_putspace(s, s->padding);
	}
	else if (s->flag_minus != 1 && s->padding > 0)
	{
		ft_putspace(s, s->padding);
		ft_putchar(c, s);
	}
	else
		ft_putchar(c, s);
}
