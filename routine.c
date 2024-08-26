/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:26:03 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/26 14:53:10 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_prog	*prog;

	prog = (void *)arg;
	while (1)
	{
		if (prog->end_flags == 1)
			return (NULL);
	}
	return (prog);
}

int	philo_eating(t_prog *prog, t_philo philo)
{
	pthread_mutex_lock(&prog->forks[philo.r_fork]);
	print_action(prog, philo, CYAN"has taken a fork"RESET);
	if (is_dead(prog, philo) == -1)
		return (-1);
	pthread_mutex_lock(&prog->forks[philo.l_fork]);
	print_action(prog, philo, CYAN"has taken a fork"RESET);
	philo.last_eat = my_get_time();
	print_action(prog, philo, GREEN"is eating . . ."RESET);
	usleep(prog->tte * 1000);
	philo.limits++;
	pthread_mutex_unlock(&prog->forks[philo.l_fork]);
	pthread_mutex_unlock(&prog->forks[philo.r_fork]);
	return (0);
}

int	philo_sleeping(t_prog *prog, t_philo philo)
{
	print_action(prog, philo, YELLOW"is sleeping"RESET);
	if (my_usleep(prog, philo, prog->tts) == -1)
	{
		print_action(prog, philo, RED BOLD"is dead"RESET);
		return (-1);
	}
	return (0);	
}

int	philo_thinking(t_prog *prog, t_philo philo)
{
	print_action(prog, philo, BLUE"is thinking"RESET);
	usleep(200000);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_prog	*prog;
	t_philo	*philo;
	int		i;

	philo = (void *)arg;
	prog = philo->prog;
	i = 0;
	if (philo->id % 2 == 0)
		usleep(500);
	while (my_get_time() < prog->start + (20 * prog->nbr))
	while (i != prog->limits)
	{
		if (philo_eating(prog, *philo) == -1)
			return (NULL);
		if (philo_sleeping(prog, *philo) == -1)
			return (NULL);
		philo_thinking(prog, *philo);
		i++;
	}
	return (prog);
}
