/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:05:53 by nomoon            #+#    #+#             */
/*   Updated: 2021/10/23 10:49:58 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_input
{
	long			total_phi;
	long			index_phi;
	long			die;
	long			eat;
	long			sleep;
	long			must_eat;
	int				statut;
	struct timeval	start;
	long			time_last_dish;
	int				stop;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_t		*phi;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*mutex_finish;
	pthread_mutex_t	*clock;
}		t_input;

typedef struct s_sg
{
	int	finish;
}				t_sg;

#endif
