/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:29:51 by elbouju           #+#    #+#             */
/*   Updated: 2019/10/23 18:16:42 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_c(long n)
{
	if (n < 10)
		return (1);
	return (1 + ft_count_c(n / 10));
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				size;

	nb = (n < 0 ? -n : n);
	size = (n >= 0 ? 0 : 1);
	size = (n == -2147483648 ? 11 : size + ft_count_c(nb));
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
