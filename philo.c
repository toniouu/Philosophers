/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:41:06 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/29 14:34:22 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	no_more_life(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nbr)
	{
		if (prog->philos[i].id % 2 == 0)
			usleep(1000);
		if (my_get_time() - prog->philos[i].last_eat >= prog->ttd)
		{
			prog->end_flags = prog->philos[i].id;
			return (-1);
		}
		if (prog->philos[i].limits == prog->limits)
		{
			prog->end_flags++;
			return (0);
		}
		i++;
	}
	return (0);
}

int	one_philo(t_prog *prog, t_philo *philo)
{
	if (prog->nbr == 1)
	{
		pthread_mutex_lock(&prog->forks[philo->r_fork]);
		print_action(prog, *philo, CYAN"has taken a fork"RESET);
		usleep(prog->ttd * 1000);
		pthread_mutex_unlock(&prog->forks[philo->r_fork]);
		prog->end_flags = 1;
		return (-1);
	}
	return (0);
}

int	init_prog(t_prog *prog)
{
	int	i;

	i = -1;
	prog->start = my_get_time() + (25 * prog->nbr);
	prog->end_flags = 0;
	// pthread_mutex_init(&prog->flags, NULL);
	while (i++ < prog->nbr - 1)
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
		prog->philos[i].last_eat = prog->start + (25 * prog->nbr);
		prog->philos[i].limits = 0;
		prog->philos[i].prog = prog;
	}
	return (0);
}
