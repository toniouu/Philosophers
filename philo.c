/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:41:06 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/19 14:22:37 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	init_forks(t_prog *prog)
{
	t_fork	*forks;
	int		i;

	i = 0;
	forks = malloc(sizeof(t_fork) * (prog->nbr));
	if (!forks)
		return ;
	while (i < prog->nbr)
	{
		pthread_mutex_init(&forks[i].fork, NULL);
		forks[i].fork_id = i;
		i++;
	}
	prog->forks = forks;
}

void	init_philos(t_prog *prog)
{
	int		i;

	i = 0;
	init_forks(prog);
	prog->philos = malloc(sizeof(t_philo) * (prog->nbr));
	if (!prog->philos)
		return ;
	while (i < prog->nbr)
	{
		prog->philos[i].id = i + 1;
		prog->philos[i].left = &prog->forks[i];
		prog->philos[i].right = &prog->forks[i + 1];
		pthread_create(&prog->philos[i].philo, NULL, routine, prog);
		pthread_join(prog->philos[i].philo, NULL);
		i++;
	}
}
