/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoon <nomoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:05:53 by nomoon            #+#    #+#             */
/*   Updated: 2021/10/22 16:44:43 by nomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_FUNC_H
# define PHILO_ONE_FUNC_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include "philo_one_struct.h"
# include <unistd.h>
# define DEAD 0
# define THINK 1
# define TAKE_FORK 2
# define EAT 3
# define SLEEP 4

long	ft_atol(char *str);
int		parse(t_input *arg, char **av, int ac);
int		stock_input(t_input *arg, char **av, int ac);
void	free_programm(t_input *tmp);
t_input	*init_struct(t_input *arg, int ac);
void	*time_to_eat(void *tmp);
void	init_thread_mutex(t_input *tmp);
long	get_current_time(struct timeval *start);
void	ft_putnbr(long num);
int		checking(t_input *tmp, int ac);
void	create_sentence(long philo, int statut, long time, char *str);
int		ft_strlen(char *str);
t_sg	*sg(void);
void	print_fork(t_input *tmp);
void	printf_lock(long philo, int statut, t_input *cpy);
void	ft_sleep(long sleep);

#endif
