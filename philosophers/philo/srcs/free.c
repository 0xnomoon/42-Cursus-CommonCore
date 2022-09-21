/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoon <nomoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:05:53 by nomoon            #+#    #+#             */
/*   Updated: 2021/10/22 16:44:28 by nomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

void	free_programm(t_input *tmp)
{
	long	i;

	i = 0;
	while (i < tmp->total_phi)
	{
		pthread_join(tmp->phi[i], NULL);
		i++;
	}
	i = 0;
	while (i < tmp->total_phi)
	{
		pthread_mutex_destroy(&tmp->fork[i]);
		i++;
	}
	pthread_mutex_destroy(tmp->mutex_print);
	pthread_mutex_destroy(tmp->mutex_finish);
	pthread_mutex_destroy(tmp->clock);
	free(tmp->mutex_finish);
	free(tmp->clock);
	free(tmp->phi);
	free(tmp->fork);
	free(tmp->mutex_print);
	free(tmp);
	free(sg());
}
