/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_pourcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:14:30 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:40:05 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_pourcent(t_printf *s)
{
	if (s->flag_minus == 1)
	{
		ft_putchar('%', s);
		ft_putspace(s, s->padding);
	}
	else if (s->flag_o == 1)
	{
		ft_putzero(s, s->padding);
		ft_putchar('%', s);
	}
	else if (s->padding > 0)
	{
		ft_putspace(s, s->padding);
		ft_putchar('%', s);
	}
	else
		ft_putchar('%', s);
}
