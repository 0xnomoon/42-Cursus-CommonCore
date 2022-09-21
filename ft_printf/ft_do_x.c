/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:38:32 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:39:17 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cutxp1(t_printf *s, unsigned int nb, int indic, int size)
{
	if (s->precision_len == 0 && s->precision == 1 && nb == 0)
		s->padding -= size - 1;
	if (s->padding > size && s->precision_len > size)
		s->padding -= s->precision_len;
	else if (s->precision_len <= size)
		s->padding -= size + 1;
	else if (s->precision_len < size &&
		s->precision_len + s->padding > size + 1)
		s->padding = (s->padding + s->precision_len) - (size + 1);
	ft_putspace(s, s->padding + 1);
	ft_putzero(s, s->precision_len - size);
	s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
}

void	ft_cutx(t_printf *s, unsigned int nb, int indic, int size)
{
	if (s->flag_minus == 1)
	{
		if (s->precision == 1 && s->precision_len == 0 && nb == 0)
			s->padding -= size - 1;
		if (s->padding > size && s->precision_len > size)
			s->padding -= s->precision_len;
		else if (s->precision_len <= size)
			s->padding -= size + 1;
		else if (s->precision_len < size &&
			s->precision_len + s->padding > size + 1)
			s->padding = (s->padding + s->precision_len) - (size + 1);
		ft_putzero(s, s->precision_len - size);
		s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
		ft_putspace(s, s->padding + 1);
	}
	else
		ft_cutxp1(s, nb, indic, size);
}

void	ft_do_xp1(t_printf *s, unsigned int nb, int indic, int size)
{
	if (s->precision == 1 && s->padding > s->precision_len)
		ft_cutx(s, nb, indic, size);
	else if (s->precision == 1 && s->padding <= s->precision_len)
	{
		ft_putzero(s, s->precision_len - size);
		s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
	}
	else if (s->padding > size && s->flag_minus == 0)
	{
		ft_putspace(s, s->padding - size);
		s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
	}
	else if (s->flag_minus == 1)
	{
		s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
		ft_putspace(s, s->padding - size);
	}
	else if (s->flag_minus != 1)
		s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
}

void	ft_do_x(t_printf *s, unsigned int nb, int indic)
{
	int size;

	size = ft_strlen(ft_convert_hex(nb, 1) + 1);
	if (s->precision == 1 && s->precision_len == 0 && nb == 0)
		s->p = 1;
	if (size >= s->padding && size > s->precision_len)
		s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
	else if ((s->flag_o == 1 && s->precision == 0 && s->flag_minus == 0) ||
		(s->flag_o == 1 && s->precision == 1 && s->precision_len < 0 &&
		s->flag_minus == 0))
	{
		ft_putzero(s, s->padding - size);
		s->p != 1 ? ft_putstr(ft_convert_hex(nb, indic), s) : s->p == 0;
	}
	else
		ft_do_xp1(s, nb, indic, size);
}
