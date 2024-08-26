/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:41:06 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/26 10:59:01 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_prog(t_prog *prog)
{
	int	i;

	i = 0;
	prog->start = my_get_time();
	while (i < prog->nbr)
	{
		if (pthread_mutex_init(&prog->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&prog->forks[i]);
			return (-1);
		}
		prog->philos[i].id = i + 1;
		prog->philos[i].r_fork = i;
		if (prog->philos[i].id == prog->nbr)
			prog->philos[i].l_fork = 0;
		else
			prog->philos[i].l_fork = i + 1;
		prog->philos[i].last_eat = 0;
		prog->philos[i].limits = 0;
		prog->philos[i].prog = prog;
		i++;
	}
	return (0);
}
