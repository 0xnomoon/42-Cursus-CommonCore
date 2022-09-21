/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:08:43 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:39:56 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_weirdcuts(t_printf *s, char *str)
{
	int i;

	i = -1;
	if (s->precision_len >= s->padding)
	{
		while (++i < s->precision_len && str[i] != '\0')
			ft_putchar(str[i], s);
	}
	else if (s->flag_minus == 1)
	{
		s->padding -= s->precision_len;
		while (++i < s->precision_len && str[i] != '\0')
			ft_putchar(str[i], s);
		ft_putspace(s, s->padding + 1);
	}
	else if (s->precision_len < s->padding)
	{
		s->padding -= s->precision_len;
		ft_putspace(s, s->padding + 1);
		while (++i < s->precision_len && str[i] != '\0')
			ft_putchar(str[i], s);
	}
}

void	ft_do_sp1(t_printf *s, char *str)
{
	if (s->padding > 0 && s->precision_len >= 0 && s->flag_minus == 0)
	{
		s->padding -= ft_strlen(str) - 1;
		ft_putspace(s, s->padding);
		ft_putstr(str, s);
	}
	else if (s->flag_minus != 1)
		ft_putstr(str, s);
}

void	ft_do_s(t_printf *s, char *str)
{
	if (s->precision_len < 0 && s->precision_len > ft_strlen(str) - 1)
		s->precision_len *= -1;
	if (s->precision == 1 && s->precision_len == 0)
		ft_putspace(s, s->padding + 1);
	else if (s->precision == 1 && s->precision_len < 0 &&
		s->padding > ft_strlen(str) && s->flag_minus != 1)
	{
		s->padding -= ft_strlen(str) - 1;
		ft_putspace(s, s->padding);
		ft_putstr(str, s);
	}
	else if (s->precision_len > 0 && s->precision_len < ft_strlen(str))
		ft_weirdcuts(s, str);
	else if (s->flag_minus == 1)
	{
		s->padding -= ft_strlen(str) - 1;
		ft_putstr(str, s);
		ft_putspace(s, s->padding);
	}
	else
		ft_do_sp1(s, str);
}
