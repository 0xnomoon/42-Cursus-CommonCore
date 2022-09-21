/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 05:42:50 by elbouju           #+#    #+#             */
/*   Updated: 2020/03/05 13:07:28 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	parse_path(char *str, t_map *tab)
{
	parse_path_error(str, tab);
	if (str[0] == 'N')
		tab->pathno = str + whilespace(str);
	if (str[0] == 'S' && str[1] == 'O')
		tab->pathso = str + whilespace(str);
	if (str[0] == 'W')
		tab->pathwe = str + whilespace(str);
	if (str[0] == 'E')
		tab->pathea = str + whilespace(str);
	if (str[0] == 'S' && str[1] == ' ')
		tab->pathsprite = str + whilespace(str);
	if (str[0] == 'F')
		tab->ground = str + whilenb(str);
	if (str[0] == 'C')
		tab->skybox = str + whilenb(str);
}

void	parse_map(char *str, t_map *tab)
{
	if (str[0] == '1' || str[0] == '0' || str[0] == ' ' || str[0] == '2')
	{
		if (!tab->mapcpy)
		{
			tab->mapcpy = str;
			tab->mapcpy = ft_sjoin_free(tab->mapcpy, "|", 1);
		}
		else
		{
			tab->mapcpy = ft_sjoin_free(tab->mapcpy, str, 2);
			tab->mapcpy = ft_sjoin_free(tab->mapcpy, "|", 1);
		}
	}
}

int		parseletters(char *str, t_map *tab)
{
	if (tab->mapcpy == NULL)
	{
		parseres(str, tab);
		if ((str[0] == '\n' || str[0] == '\0') || (str[0] != 'N' && str[0]
		!= 'S' && str[0] != 'W' && str[0] != 'E' && str[0] != 'F' &&
		str[0] != 'C' && str[0] != '0' && str[0] != '1' && str[0] != 'R'
		&& str[0] != ' '))
			free(str);
		parse_path(str, tab);
	}
	parse_map(str, tab);
	return (0);
}

int		ft_parse1(t_map *tab)
{
	tab->map = ft_split(tab->mapcpy, "|");
	return (0);
}

int		ft_parse(t_map *tab, int fd)
{
	int		ret;
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = -1;
	ret = 1;
	tab->mapcpy = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		parseletters(line, tab);
	}
	ft_parse1(tab);
	return (0);
}
