/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoon <nomoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:58:59 by nomoon            #+#    #+#             */
/*   Updated: 2021/10/22 16:43:47 by nomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

void	ft_sleep(long sleep)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (get_current_time(&start) < sleep)
	{
		usleep(100);
	}
}

long	get_current_time(struct timeval *start)
{
	struct timeval	end;
	long			time;

	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000 + end.tv_usec / 1000)
		- (start->tv_sec * 1000 + start->tv_usec / 1000);
	return (time);
}
