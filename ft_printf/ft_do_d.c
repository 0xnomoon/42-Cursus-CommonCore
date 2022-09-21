/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:42:25 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/13 04:07:22 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cutdp1(t_printf *s, int nb, int indic)
{
	if (nb < 0 && s->precision_len >= ft_countnum(nb))
		s->padding -= 1;
	if (s->padding > ft_countnum(nb) && s->precision_len > ft_countnum(nb))
		s->padding -= s->precision_len - 1;
	else if (s->precision_len <= ft_countnum(nb))
		s->padding -= ft_countnum(nb) - 1;
	else if (s->precision_len < ft_countnum(nb) + 1 &&
		s->precision_len + s->padding > ft_countnum(nb) + 1)
		s->padding = (s->padding + s->precision_len) - (ft_countnum(nb)) + 1;
	ft_putspace(s, s->padding);
	if (ft_countnum(nb) <= s->precision_len)
		nb *= ft_affminus(s, nb, 2);
	ft_putzero(s, s->precision_len - ft_countnum(nb) + 1);
	indic != 1 ? ft_putnbr(nb, s) : indic == 0;
}

void	ft_cutd(t_printf *s, int nb, int indic)
{
	int padprec;

	padprec = s->padding + s->precision_len;
	if (s->flag_minus == 1)
	{
		if (nb < 0 && s->precision_len >= ft_countnum(nb))
			s->padding -= 1;
		if (s->padding > ft_countnum(nb) && s->precision_len > ft_countnum(nb))
			s->padding -= s->precision_len - 1;
		else if (s->precision_len <= ft_countnum(nb))
			s->padding -= ft_countnum(nb) - 1;
		else if (s->precision_len < ft_countnum(nb) + 1
			&& s->precision_len + s->padding > ft_countnum(nb) + 1)
			s->padding = padprec - (ft_countnum(nb)) + 1;
		nb *= ft_affminus(s, nb, 2);
		ft_putzero(s, s->precision_len - ft_countnum(nb) + 1);
		indic != 1 ? ft_putnbr(nb, s) : indic == 0;
		ft_putspace(s, s->padding);
	}
	else
		ft_cutdp1(s, nb, indic);
}

int		ft_affminus(t_printf *s, int nb, int indic)
{
	if (nb < 0)
	{
		ft_putchar('-', s);
		if (indic == 1)
			s->padding -= 1;
		return (-1);
	}
	else
		return (1);
}

void	ft_do_dp1(t_printf *s, long long int nb, int indic)
{
	if (s->precision == 1 && s->padding > s->precision_len)
		ft_cutd(s, nb, indic);
	else if (s->precision == 1 && s->padding <= s->precision_len)
	{
		nb *= ft_affminus(s, nb, 2);
		ft_putzero(s, s->precision_len - ft_countnum(nb) + 1);
		indic != 1 ? ft_putnbr(nb, s) : indic == 0;
	}
	else if (s->padding > ft_countnum(nb) && s->flag_minus == 0)
	{
		ft_putspace(s, s->padding - ft_countnum(nb) + 1);
		indic != 1 ? ft_putnbr(nb, s) : indic == 0;
	}
	else if (s->flag_minus == 1)
	{
		indic != 1 ? ft_putnbr(nb, s) : indic == 0;
		ft_putspace(s, s->padding - ft_countnum(nb) + 1);
	}
	else if (s->flag_minus != 1)
		indic != 1 ? ft_putnbr(nb, s) : indic == 0;
}

void	ft_do_d(t_printf *s, int n)
{
	long long int	nb;
	int				indic;

	nb = n;
	indic = 0;
	if (s->precision == 1 && s->precision_len == 0 && nb == 0)
	{
		s->padding++;
		indic = 1;
	}
	if (ft_countnum(nb) + 1 > s->padding && ft_countnum(nb) > s->precision_len)
		indic != 1 ? ft_putnbr(nb, s) : indic == 0;
	else if ((s->flag_o == 1 && s->precision == 0 && s->flag_minus == 0) ||
			(s->flag_o == 1 && s->precision == 1 && s->precision_len < 0 &&
			s->flag_minus == 0))
	{
		nb *= ft_affminus(s, nb, 1);
		ft_putzero(s, s->padding - ft_countnum(nb) + 1);
		indic != 1 ? ft_putnbr(nb, s) : indic == 0;
	}
	else
		ft_do_dp1(s, nb, indic);
}
