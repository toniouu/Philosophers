/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:26:03 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/29 14:15:05 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_prog	*prog;
	char	*end;

	prog = (void *)arg;
	end = RED BOLD"died"RESET;
	while (1)
	{
		if (no_more_life(prog) == -1)
		{
			printf("%ld %d %s\n", my_get_time() - prog->start, prog->end_flags, end);
			return (NULL);
		}
		if (prog->end_flags == prog->nbr)
		{
			printf(MAGENTA BOLD"END OF PROG\n"RESET);
			return (NULL);
		}
	}
	return (prog);
}

int	philo_eating(t_prog *prog, t_philo *philo)
{
	philo->last_eat = my_get_time();
	if (one_philo(prog, philo) == -1)
		return (-1);
	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&prog->forks[philo->r_fork]);
	print_action(prog, *philo, CYAN"has taken a fork"RESET);
	pthread_mutex_lock(&prog->forks[philo->l_fork]);
	print_action(prog, *philo, CYAN"has taken a fork"RESET);
	philo->last_eat = my_get_time();
	print_action(prog, *philo, GREEN"is eating"RESET);
	usleep(prog->tte * 1000);
	philo->limits++;
	pthread_mutex_unlock(&prog->forks[philo->l_fork]);
	pthread_mutex_unlock(&prog->forks[philo->r_fork]);
	return (0);
}

int	philo_sleeping(t_prog *prog, t_philo *philo)
{
	if (prog->end_flags != 0)
		return (-1);
	print_action(prog, *philo, YELLOW"is sleeping"RESET);
	usleep(prog->tts * 1000);
	return (0);	
}

int	philo_thinking(t_prog *prog, t_philo *philo)
{
	long	ttt;

	if (prog->end_flags != 0)
		return (-1);
	ttt = my_get_time() - philo->last_eat - prog->tte - prog->tts;
	print_action(prog, *philo, BLUE"is thinking"RESET);
	usleep(ttt * 1000);
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
	while (my_get_time() < prog->start)
		usleep(1);
	while (1)
	{
		if (philo_eating(prog, philo) == -1)
			return (NULL);
		if (philo_sleeping(prog, philo) == -1)
			return (NULL);
		if (philo_thinking(prog, philo) == -1)
			return (NULL);
		if (philo->limits == philo->prog->limits)
			break;
	}
	return (prog);
}
