/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:17:53 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/13 04:01:23 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parsedot(char *str, va_list args, t_printf *s)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		s->precision = 1;
		if (ft_letter(str[i + 1]) == 1)
			i++;
		if ((ft_isdigit(str[i]) == 1) || (str[i] == '-'
			&& ft_isdigit(str[i + 1]) == 1))
		{
			s->precision_len = ft_atoi(&str[i]);
			if (str[i] == '-')
				i++;
		}
		else if (str[i] == '*')
			s->precision_len = va_arg(args, int);
	}
	return (i);
}

int			ft_parseminusdigit(char *str, va_list args, t_printf *s)
{
	int i;

	i = 0;
	if (str[i] == '-')
		s->flag_minus = 1;
	else if (ft_isdigit(str[i]) == 1)
	{
		if (str[i] == '0')
		{
			s->flag_o = 1;
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
		}
		s->padding = ft_atoi(&str[i]);
	}
	else if (str[i] == '*')
	{
		s->padding = va_arg(args, int);
		if (s->padding < 0)
		{
			s->flag_minus = 1;
			s->padding *= -1;
		}
	}
	return (i);
}

int			ft_parse(char *str, va_list args)
{
	int				i;
	int				y;
	int				k;
	t_printf		*s;

	i = 0;
	y = 0;
	s = init_struct();
	while (str[i] && ft_letter(str[i]) == 1)
	{
		y = 1;
		if (str[i] == '-' || ft_isdigit(str[i]) == 1 || str[i] == '*')
			i += ft_parseminusdigit(&str[i], args, s);
		else if (str[i] == '.')
			i += ft_parsedot(&str[i], args, s);
		y += ft_passnum(&str[i]) - 1;
		i += y;
	}
	ft_callfunc(str[i], s, args);
	k = s->count;
	free(s);
	return (k);
}

int			ft_callparse(char *str, va_list args)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '%')
		{
			i++;
			count += ft_parse(&str[i], args);
			while (str[i] && ft_letter(str[i]) == 1)
				i++;
			i++;
		}
		else
		{
			count += write(1, &str[i], 1);
			i++;
		}
	}
	return (count);
}

int			ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	return (ft_callparse((char*)str, args));
}
