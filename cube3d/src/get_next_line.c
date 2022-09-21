/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:34:24 by elbouju           #+#    #+#             */
/*   Updated: 2020/02/24 18:35:18 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	if (!s)
		return (NULL);
	str = (char*)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

int		endofline(char **str, char *pos, char *pos2, char **line)
{
	if (*str && (pos2 = ft_strchr(*str, '\n')) != NULL)
	{
		pos2[0] = '\0';
		*line = sdupfr(*str, 0);
		pos = sdupfr(pos2 + 1, 0);
		free(*str);
		*str = pos;
		return (1);
	}
	else
	{
		if (!*str)
			*line = sdupfr("", 0);
		else
			*line = sdupfr(*str, 0);
		return (0);
	}
	return (0);
}

int		posnonull(char **line, char **str, char *buff, t_list spl)
{
	spl.pos[0] = (ft_strchr(*str, '\n') == NULL ? '\0' : spl.pos[0]);
	if (*str != NULL)
	{
		spl.pos2 = ft_strchr(*str, '\n');
		if (spl.pos2 == NULL)
			*line = ft_sjoin_free(*str, buff, 1);
		else
		{
			spl.pos2[0] = '\0';
			*line = sdupfr(*str, 0);
			spl.pos = ft_sjoin_free(spl.pos2 + 1, buff, 0);
			free(*str);
			*str = spl.pos;
			return (1);
		}
	}
	else
		*line = sdupfr(buff, 0);
	*str = sdupfr(spl.pos + 1, 0);
	return (1);
}

int		rdline(char **line, char **str, t_list spl, char *buff)
{
	while ((spl.ret = read(spl.fd_tp, buff, BUFFER_SIZE)) > 0)
	{
		buff[spl.ret] = '\0';
		spl.pos = ft_strchr(buff, '\n');
		if (spl.pos != NULL)
		{
			posnonull(line, str, buff, spl);
			break ;
		}
		else
			*str = (!(*str) ? sdupfr(buff, 0) : ft_sjoin_free(*str, buff, 1));
	}
	if (spl.ret == 0)
		spl.ret = endofline(str, spl.pos, spl.pos2, line);
	return (spl.ret);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	char			*buff;
	int				keuf;
	t_list			spl;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	spl.fd_tp = fd;
	keuf = rdline(line, &str, spl, buff);
	free(buff);
	if (str && keuf <= 0)
	{
		free(str);
		str = NULL;
	}
	return (keuf > 0 ? 1 : keuf);
}
