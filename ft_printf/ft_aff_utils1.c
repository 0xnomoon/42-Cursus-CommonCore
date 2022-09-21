/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:16:25 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/12 19:41:02 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int i;
	int neg;

	neg = 1;
	i = 0;
	while (*str != '\0' && (*str == '\t' || *str == '\n' || *str == '\r' ||
				*str == '\v' || *str == '\f' || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (i * neg);
}

int		ft_count_hex(long long int n)
{
	if (n < 16)
		return (1);
	return (1 + ft_count_hex(n / 16));
}

char	*ft_convert_hex(long long int nb, int indic)
{
	char	*base;
	char	*result;
	int		size;

	if (nb == 0)
		return ("0");
	size = ft_count_hex(nb);
	if (indic == 1)
		base = "0123456789ABCDEF";
	if (indic == 2)
		base = "0123456789abcdef";
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	result[size] = '\0';
	size--;
	while (nb != 0)
	{
		result[size] = base[nb % 16];
		size--;
		nb /= 16;
	}
	return (result);
}

void	ft_putstr(char *str, t_printf *s)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], s);
}

int		ft_countnum(long long nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	i += ft_count_base(nb);
	return (i);
}
