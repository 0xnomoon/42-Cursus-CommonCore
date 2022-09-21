/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 00:10:04 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:42:52 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*init_struct(void)
{
	t_printf	*new;

	new = NULL;
	if (!(new = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	new->count = 0;
	new->flag_minus = 0;
	new->flag_o = 0;
	new->padding = 0;
	new->precision = 0;
	new->precision_len = 0;
	new->p = 0;
	return (new);
}

int			ft_callfunc(char c, t_printf *s, va_list args)
{
	char *str;

	if (c == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		ft_do_s(s, str);
	}
	if (c == 'd' || c == 'i')
		ft_do_d(s, va_arg(args, int));
	if (c == 'c')
		ft_do_c(s, va_arg(args, int));
	if (c == 'p')
		ft_do_p(s, va_arg(args, long long int));
	if (c == 'u')
		ft_do_u(s, va_arg(args, unsigned int));
	if (c == 'X')
		ft_do_x(s, va_arg(args, unsigned int), 1);
	if (c == 'x')
		ft_do_x(s, va_arg(args, unsigned int), 2);
	if (c == '%')
		ft_do_pourcent(s);
	return (1);
}
