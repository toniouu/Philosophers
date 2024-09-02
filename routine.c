/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:26:03 by atovoman          #+#    #+#             */
/*   Updated: 2024/09/02 12:57:34 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_prog	*prog;
	char	*end;

	prog = (void *)arg;
	prog->l_flags = 0;
	end = RED BOLD"died"RESET;
	while (1)
	{
		if (no_more_life(prog) == -1)
		{
			printf("%ld %d %s\n",
				my_get_time() - prog->start, prog->end_flags, end);
			return (NULL);
		}
		if (prog->l_flags == prog->nbr)
		{
			prog->end_flags = -1;
			break ;
		}
	}
	return (prog);
}

int	philo_eating(t_prog *prog, t_philo *philo)
{
	philo->last_eat = my_get_time();
	if (one_philo(prog, philo) == -1)
		return (-1);
	if (philo->id % 2 == 0 && philo->starting == 0)
	{
		if (my_usleep(prog, *philo, prog->tte) == -1)
			return (-1);
		else
			philo->starting++;
	}
	pthread_mutex_lock(&prog->forks[philo->r_fork]);
	if (prog->end_flags != 0)
		return (-1);
	print_action(prog, *philo, CYAN"has taken a fork"RESET);
	pthread_mutex_lock(&prog->forks[philo->l_fork]);
	print_action(prog, *philo, CYAN"has taken a fork"RESET);
	print_action(prog, *philo, GREEN"is eating"RESET);
	philo->last_eat = my_get_time();
	usleep(prog->tte * 1000);
	philo->limits++;
	pthread_mutex_unlock(&prog->forks[philo->l_fork]);
	pthread_mutex_unlock(&prog->forks[philo->r_fork]);
	if (prog->end_flags != 0)
		return (-1);
	return (0);
}

int	philo_sleeping(t_prog *prog, t_philo *philo)
{
	if (prog->end_flags != 0)
		return (-1);
	print_action(prog, *philo, YELLOW"is sleeping"RESET);
	if (my_usleep(prog, *philo, prog->tts) == -1)
		return (-1);
	return (0);
}

int	philo_thinking(t_prog *prog, t_philo *philo)
{
	long	ttt;

	if (prog->end_flags != 0)
		return (-1);
	ttt = my_get_time() - philo->last_eat
		- prog->tte - prog->tts + (prog->nbr + 1);
	print_action(prog, *philo, BLUE"is thinking"RESET);
	if (my_usleep(prog, *philo, ttt) == -1)
		return (-1);
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
		if (philo_eating(prog, philo) == -1 || philo->prog->end_flags != 0)
			break ;
		if (philo_sleeping(prog, philo) == -1 || philo->prog->end_flags != 0)
			break ;
		if (philo_thinking(prog, philo) == -1 || philo->prog->end_flags != 0)
			break ;
		if (philo->limits == prog->limits)
			break ;
	}
	return (NULL);
}
