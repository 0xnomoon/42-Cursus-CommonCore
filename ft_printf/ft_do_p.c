/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:41:19 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:40:12 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_p(t_printf *s, long long nb)
{
	if (s->flag_minus == 1)
	{
		s->padding -= (ft_strlen(ft_convert_hex(nb, 2)) + 1);
		ft_putstr("0x", s);
		ft_putstr(ft_convert_hex(nb, 2), s);
		ft_putspace(s, s->padding);
	}
	else if (s->flag_minus != 1 && s->padding > 0)
	{
		s->padding -= (ft_strlen(ft_convert_hex(nb, 2)) + 1);
		ft_putspace(s, s->padding);
		ft_putstr("0x", s);
		ft_putstr(ft_convert_hex(nb, 2), s);
	}
	else
	{
		ft_putstr("0x", s);
		ft_putstr(ft_convert_hex(nb, 2), s);
	}
}
