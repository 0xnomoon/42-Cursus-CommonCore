/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:35:02 by elbouju           #+#    #+#             */
/*   Updated: 2019/11/04 15:47:57 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	char	*pos;
	char	*pos2;
	int		ret;
	int		fd_tp;
}					t_list;
int					get_next_line(int fd, char **line);
int					rdline(char **line, char **str, t_list spl, char *buff);
int					checkerror_gnl(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*sdupfr(char *s1, size_t n);
char				*ft_sjoin_free(char const *dst, char const *src, size_t n);
size_t				ft_strlen(const char *str);
int					endofline(char **str, char *pos, char *pos2, char **line);
int					posnonull(char **line, char **str, char *buff, t_list spl);

#endif
