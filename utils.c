/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:42:47 by atovoman          #+#    #+#             */
/*   Updated: 2024/09/13 16:43:48 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	print_error(char *error)
{
	printf(RED BOLD"ERROR : %s\n", error);
}

void	print_action(t_prog *prog, t_philo philo, char *action)
{
	if (check_end_flag(prog) == -1)
		return ;
	pthread_mutex_lock(&prog->write_lock);
	printf("%ld %d %s\n", my_get_time() - prog->start, philo.id, action);
	pthread_mutex_unlock(&prog->write_lock);
}

int	my_usleep(t_prog *prog, t_philo philo, long t)
{
	long	act;

	act = my_get_time();
	while (my_get_time() <= act + t)
	{
		pthread_mutex_lock(&prog->dead_lock);
		if (my_get_time() - philo.last_eat >= prog->ttd)
		{
			pthread_mutex_unlock(&prog->dead_lock);
			return (-1);
		}
		pthread_mutex_unlock(&prog->dead_lock);
		if (check_end_flag(prog) == -1)
			return (-1);
		usleep(500);
	}
	return (0);
}
