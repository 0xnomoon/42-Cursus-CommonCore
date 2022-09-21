/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoon <nomoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:52:15 by nomoon            #+#    #+#             */
/*   Updated: 2021/10/22 16:44:35 by nomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

int	unlock_mutex(t_input *tmp)
{
	long	time;

	time = get_current_time(&tmp->start);
	if (time - tmp->time_last_dish > tmp->die)
	{
		printf_lock(tmp->index_phi, DEAD, tmp);
		sg()->finish = 1;
		pthread_mutex_unlock(tmp->clock);
		return (0);
	}
	return (1);
}

int	philo_endless_hungry(t_input *tmp)
{
	long	i;

	i = 0;
	while (i < tmp->total_phi)
	{
		pthread_mutex_lock(tmp->clock);
		if (unlock_mutex(&tmp[i]) == 0)
			return (1);
		pthread_mutex_unlock(tmp->clock);
		i++;
		if (i == tmp->total_phi)
			i = 0;
	}
	return (0);
}

int	philo_defined_hungry(t_input *tmp)
{
	long	i;
	long	count;

	i = 0;
	count = 0;
	while (i < tmp->total_phi)
	{
		pthread_mutex_lock(tmp->clock);
		if (tmp[i].must_eat == 0)
			count++;
		if (unlock_mutex(&tmp[i]) == 0)
			return (1);
		pthread_mutex_unlock(tmp->clock);
		i++;
		if (count == tmp->total_phi)
			break ;
		else if (i == tmp->total_phi)
		{
			i = 0;
			count = 0;
		}
	}
	return (1);
}

int	checking(t_input *tmp, int ac)
{
	init_thread_mutex(tmp);
	if (ac == 5)
	{
		if (philo_endless_hungry(tmp) == 1)
			return (1);
	}
	else if (ac == 6)
	{
		if (philo_defined_hungry(tmp) == 1)
			return (1);
	}
	return (0);
}
