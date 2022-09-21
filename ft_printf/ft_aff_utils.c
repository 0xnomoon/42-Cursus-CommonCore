/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:04:33 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:41:25 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putchar(char c, t_printf *s)
{
	s->count += 1;
	write(1, &c, 1);
}

int			ft_count_base(long long int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_count_base(n / 10));
}

char		*ft_itoa(long long n)
{
	char			*str;
	unsigned int	nb;
	int				size;

	nb = (n < 0 ? -n : n);
	size = (n >= 0 ? 0 : 1);
	size = (n == -2147483648 ? 11 : size + ft_count_base(nb));
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size--] = '\0';
	if (n == -2147483648)
	{
		str[size--] = '8';
		nb /= 10;
	}
	str[0] = (n < 0 ? '-' : 0);
	while ((size >= 0 && n >= 0) || (n < 0 && size > 0))
	{
		str[size--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

void		ft_putnbr(long long nb, t_printf *s)
{
	long long i;

	i = nb;
	if (i < 0)
	{
		ft_putchar('-', s);
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10, s);
		ft_putnbr(i % 10, s);
	}
	else if (i == 0)
		ft_putchar('0', s);
	else
		ft_putchar('0' + i, s);
}
