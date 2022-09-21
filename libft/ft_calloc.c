/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:02:07 by elbouju           #+#    #+#             */
/*   Updated: 2019/10/21 18:44:04 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			res;
	void			*temp;

	res = size * count;
	if (!(temp = (char *)malloc(sizeof(char) * res)))
		return (NULL);
	ft_bzero(temp, res);
	return (temp);
}
