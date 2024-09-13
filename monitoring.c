/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:21:37 by atovoman          #+#    #+#             */
/*   Updated: 2024/09/13 11:36:57 by atovoman         ###   ########.fr       */
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
	while (my_get_time() < prog->start)
		usleep(1);
	while (1)
	{
		if (no_more_life(prog) == -1)
		{
			pthread_mutex_lock(&prog->write_lock);
			printf("%ld %d %s\n",
				my_get_time() - prog->start, prog->end_flags, end);
			pthread_mutex_unlock(&prog->write_lock);
			return (NULL);
		}
		if (is_finished(prog) == 0)
			break ;
		usleep(100);
	}
	return (prog);
}
