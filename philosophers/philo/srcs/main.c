/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:07:32 by nomoon            #+#    #+#             */
/*   Updated: 2021/10/23 10:49:43 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

int	main(int ac, char **av)
{
	t_input	arg;
	t_input	*tmp;

	if (ac == 5 || ac == 6)
	{
		if (parse(&arg, av, ac) == 1)
		{
			printf("Error\nParse\n");
			return (0);
		}
		tmp = init_struct(&arg, ac);
		if (checking(tmp, ac) == 1)
			free_programm(tmp);
	}
	else
		printf("Error\nNumber arg false\n");
	return (0);
}
