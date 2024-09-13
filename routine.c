/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:26:03 by atovoman          #+#    #+#             */
/*   Updated: 2024/09/13 16:44:41 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	harmony(t_prog *prog, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&prog->forks[philo->r_fork]);
		if (check_end_flag(prog) == -1)
		{
			pthread_mutex_unlock(&prog->forks[philo->r_fork]);
			return (-1);
		}
		print_action(prog, *philo, CYAN"has taken a fork"RESET);
		pthread_mutex_lock(&prog->forks[philo->l_fork]);
	}
	else
	{
		pthread_mutex_lock(&prog->forks[philo->l_fork]);
		if (check_end_flag(prog) == -1)
		{
			pthread_mutex_unlock(&prog->forks[philo->l_fork]);
			return (-1);
		}
		print_action(prog, *philo, CYAN"has taken a fork"RESET);
		pthread_mutex_lock(&prog->forks[philo->r_fork]);
	}
	return (0);
}

int	philo_eating(t_prog *prog, t_philo *philo)
{
	if (philo->id % 2 == 0 && philo->starting++ == 0)
	{
		if (my_usleep(prog, *philo, prog->tte) == -1)
			return (-1);
	}
	if (harmony(prog, philo) == -1)
		return (-1);
	print_action(prog, *philo, CYAN"has taken a fork"RESET);
	print_action(prog, *philo, GREEN"is eating"RESET);
	pthread_mutex_lock(&prog->dead_lock);
	philo->last_eat = my_get_time();
	pthread_mutex_unlock(&prog->dead_lock);
	usleep(prog->tte * 1000);
	pthread_mutex_unlock(&prog->forks[philo->l_fork]);
	pthread_mutex_unlock(&prog->forks[philo->r_fork]);
	pthread_mutex_lock(&prog->dead_lock);
	philo->limits++;
	pthread_mutex_unlock(&prog->dead_lock);
	if (check_end_flag(prog) == -1)
		return (-1);
	return (0);
}

int	philo_sleeping(t_prog *prog, t_philo *philo)
{
	if (check_end_flag(prog) == -1)
		return (-1);
	print_action(prog, *philo, YELLOW"is sleeping"RESET);
	if (my_usleep(prog, *philo, prog->tts) == -1)
		return (-1);
	return (0);
}

int	philo_thinking(t_prog *prog, t_philo *philo)
{
	if (check_end_flag(prog) == -1)
		return (-1);
	print_action(prog, *philo, BLUE"is thinking"RESET);
	usleep(1);
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
		if (prog->nbr == 1)
			break ;
		if (philo_eating(prog, philo) == -1)
			break ;
		if (philo_sleeping(prog, philo) == -1)
			break ;
		if (philo_thinking(prog, philo) == -1)
			break ;
		if (philo->limits == prog->limits)
			break ;
	}
	return (NULL);
}
