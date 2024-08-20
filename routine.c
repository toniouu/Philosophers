/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:26:03 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/20 12:36:16 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_philo philo)
{
	printf(GREEN"Philo [%d] is eating . . . \n"RESET, philo.id);
}

void	philo_sleeping(t_philo philo)
{
	printf(YELLOW"Philo [%d] is sleeping . . . \n"RESET, philo.id);
}

void	philo_thinking(t_philo philo)
{
	printf(BLUE"Philo [%d] is thinking . . . \n"RESET, philo.id);
}

void	*routine(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	while (my_get_time()->tv_sec < prog->start + (20 * prog->nbr))
		usleep(2);
	while ()
	
	
}
