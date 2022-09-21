/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:59:09 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:39:36 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cutup1(t_printf *s, unsigned int nb, int size, int indic)
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
	indic != 1 ? ft_putnbr(nb, s) : indic == 1;
}

void	ft_cutu(t_printf *s, unsigned int nb, int size, int indic)
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
		indic != 1 ? ft_putnbr(nb, s) : indic == 1;
		ft_putspace(s, s->padding + 1);
	}
	else
		ft_cutup1(s, nb, size, indic);
}

void	ft_do_up1(t_printf *s, unsigned int nb, int size, int indic)
{
	if (s->precision == 1 && s->padding > s->precision_len)
		ft_cutu(s, nb, size, indic);
	else if (s->precision == 1 && s->padding <= s->precision_len)
	{
		ft_putzero(s, s->precision_len - size);
		indic != 1 ? ft_putnbr(nb, s) : indic == 1;
	}
	else if (s->padding > size && s->flag_minus == 0)
	{
		ft_putspace(s, s->padding - size);
		indic != 1 ? ft_putnbr(nb, s) : indic == 1;
	}
	else if (s->flag_minus == 1)
	{
		indic != 1 ? ft_putnbr(nb, s) : indic == 1;
		ft_putspace(s, s->padding - size);
	}
	else if (s->flag_minus != 1)
		indic != 1 ? ft_putnbr(nb, s) : indic == 1;
}

void	ft_do_u(t_printf *s, unsigned int nb)
{
	int size;
	int indic;

	indic = 0;
	size = ft_count_base(nb) - 1;
	if (s->precision == 1 && s->precision_len == 0 && nb == 0)
		indic = 1;
	if (size > s->padding && size > s->precision_len)
		ft_putnbr(nb, s);
	else if ((s->flag_o == 1 && s->precision == 0 && s->flag_minus == 0) ||
			(s->flag_o == 1 && s->precision == 1 && s->precision_len < 0 &&
			s->flag_minus == 0))
	{
		ft_putzero(s, s->padding - size);
		indic != 1 ? ft_putnbr(nb, s) : indic == 1;
	}
	else
		ft_do_up1(s, nb, size, indic);
}
