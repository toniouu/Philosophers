/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:41:06 by atovoman          #+#    #+#             */
/*   Updated: 2024/09/13 16:51:19 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end_flag(t_prog *prog)
{
	pthread_mutex_lock(&prog->dead_lock);
	if (prog->end_flags != 0)
	{
		pthread_mutex_unlock(&prog->dead_lock);
		return (-1);
	}
	pthread_mutex_unlock(&prog->dead_lock);
	return (0);
}

int	is_finished(t_prog *prog)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < prog->nbr)
	{
		pthread_mutex_lock(&prog->dead_lock);
		if (prog->philos[i].limits == prog->limits)
			result++;
		pthread_mutex_unlock(&prog->dead_lock);
		if (result == prog->nbr)
			return (0);
		i++;
	}
	return (-1);
}

int	no_more_life(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nbr)
	{
		if (prog->philos[i].id % 2 == 0)
			usleep(1000);
		pthread_mutex_lock(&prog->dead_lock);
		if (my_get_time() - prog->philos[i].last_eat >= prog->ttd
			&& prog->philos[i].limits != prog->limits)
		{
			prog->end_flags = prog->philos[i].id;
			pthread_mutex_unlock(&prog->dead_lock);
			return (-1);
		}
		pthread_mutex_unlock(&prog->dead_lock);
		i++;
	}
	return (0);
}

int	one_philo(t_prog *prog, t_philo *philo)
{
	if (prog->nbr == 1)
	{
		while (my_get_time() < prog->start)
			usleep(1);
		pthread_join(philo->philo, NULL);
		pthread_mutex_lock(&prog->forks[philo->r_fork]);
		print_action(prog, *philo, CYAN"has taken a fork"RESET);
		usleep(prog->ttd * 1000);
		print_action(prog, *philo, RED BOLD"died"RESET);
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
	prog->start = my_get_time() + (50 * prog->nbr);
	prog->end_flags = 0;
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
		prog->philos[i].last_eat = prog->start;
		prog->philos[i].limits = 0;
		prog->philos[i].prog = prog;
		prog->philos[i].starting = 0;
	}
	return (0);
}
