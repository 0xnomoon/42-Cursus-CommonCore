/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:17:53 by elbouju           #+#    #+#             */
/*   Updated: 2019/12/13 04:02:57 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_printf
{
	int			padding;
	int			precision;
	int			precision_len;
	int			flag_o;
	int			flag_minus;
	int			count;
	int			p;
}				t_printf;

long long		ft_strlen(char *str);
void			ft_putchar(char c, t_printf *s);
int				ft_count_base(long long int n);
char			*ft_itoa(long long n);
void			ft_putnbr(long long nb, t_printf *s);
int				ft_atoi(const char *str);
int				ft_count_hex(long long int n);
char			*ft_convert_hex(long long int nb, int indic);
void			ft_putstr(char *str, t_printf *s);
int				ft_isdigit(int c);
int				ft_letter(char c);
void			ft_do_s(t_printf *s, char *str);
void			ft_putzero(t_printf *s, int size);
void			ft_putspace(t_printf *s, int size);
int				ft_passnum(char *str);
void			ft_do_d(t_printf *s, int nb);
int				ft_affminus(t_printf *s, int nb, int indic);
void			ft_do_c(t_printf *s, char c);
void			ft_do_p(t_printf *s, long long nb);
void			ft_do_u(t_printf *s, unsigned int nb);
void			ft_do_x(t_printf *s, unsigned int nb, int indic);
void			ft_do_pourcent(t_printf *s);
int				ft_countnum(long long nb);
t_printf		*init_struct(void);
int				ft_callfunc(char c, t_printf *s, va_list args);
int				ft_printf(const char *str, ...);

#endif
