/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:13:27 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/26 11:37:31 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "colors.h"

typedef pthread_mutex_t	t_mtx;
typedef struct s_prog t_prog;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	int				l_fork;
	int				r_fork;
	long			last_eat;
	int				limits;
	t_prog			*prog;
}	t_philo;

typedef struct s_prog
{
	long			nbr;
	long			ttd;
	long			tte;
	long			tts;
	long			limits;
	long			start;
	int				end_flags;
	pthread_t		monitor;
	t_philo			philos[250];
	t_mtx			forks[250];
}	t_prog;

void	print_error(char *error);
void	print_action(t_prog *prog, t_philo philo, char *action);

void	*philo_routine(void *arg);

int		ft_is_digit(char c);
int		check_if_not_digit(char **av);
int		init_prog(t_prog *prog);
int		my_usleep(t_prog *prog, t_philo philo, long time);

long	ft_atoi(char *nbr);
long	my_get_time();

#endif