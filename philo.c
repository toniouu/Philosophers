/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:41:06 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/20 12:36:18 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	starting_prog(t_prog *prog)
{
	int	i;

	i = 0;
	prog->start = my_get_time()->tv_sec;
	while (i < prog->nbr)
	{
		prog->philos[i].id = i + 1;
		prog->philos[i].r_fork = i;
		if (prog->philos[i].id == prog->nbr)
			prog->philos[i].l_fork = 0;
		else
			prog->philos[i].l_fork = i + 1;
		pthread_create(&prog->philos[i], NULL, routine, prog);
		i++;
	}
}

void	init_forks(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nbr)
	{
		pthread_mutex_init(&prog->forks[i].fork, NULL);
		prog->forks[i].fork_id = i;
		i++;
	}
}
