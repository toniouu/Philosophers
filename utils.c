/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:42:47 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/29 14:34:41 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	is_dead(t_prog *prog, t_philo *philo)
// {
// 	long	act;

// 	act = my_get_time();
// 	if (my_get_time() - philo->last_eat >= prog->ttd)
// 	{
// 		pthread_mutex_lock(&prog->flags);
// 		prog->end_flags = philo->id;
// 		pthread_mutex_unlock(&prog->flags);
// 		return (-1);
// 	}
// 	return (0);
// }

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
	if (prog->end_flags != 0)
		return ;
	printf("%ld %d %s\n", my_get_time() - prog->start, philo.id, action);
}

// int	my_usleep(t_prog *prog, t_philo philo, long time)
// {
// 	long	act;

// 	act = my_get_time();
// 	if (prog->end_flags != 0)
// 		return (-1);
// 	while (my_get_time() < act + time)
// 	{
// 		if (is_dead(prog, &philo) == -1)
// 			return (-1);
// 		usleep(100);
// 	}
// 	return (0);
// }
