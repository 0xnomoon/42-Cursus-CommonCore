/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:31:52 by elbouju           #+#    #+#             */
/*   Updated: 2019/10/28 13:00:35 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		if (!(ret = malloc(sizeof(char))))
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		ret[i] = (char)s[i + start];
		len--;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
