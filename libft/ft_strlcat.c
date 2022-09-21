/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:00:16 by elbouju           #+#    #+#             */
/*   Updated: 2019/10/28 12:58:46 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char		*dest;
	const char		*source;
	size_t			len;
	size_t			size;

	dest = (const char*)dst;
	source = src;
	len = dstsize;
	while (len-- != 0 && *dst != '\0')
		dst++;
	size = dst - dest;
	len = dstsize - size;
	if (len-- == 0)
		return (size + ft_strlen(src));
	while (*src != '\0')
	{
		if (len != 0)
		{
			*dst++ = *src;
			len--;
		}
		src++;
	}
	*dst = '\0';
	return (size + (src - source));
}
