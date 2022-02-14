/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:26:26 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/14 16:43:49 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_philo {
	pthread_t t;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	int	index;
	int	t_he_eat;
	int	state;
}				t_philo;

typedef struct s_time {
	int	n_philo;
	int	t_to_die;
	int t_to_eat;
	int t_to_sleep;
	int	n_time_eat;
}				t_time;

typedef struct s_struct {
	t_time	base;
}				t_struct;

t_philo	*init_philo(t_struct *global);

void	error_arg(int ac);
void	init_time(char **av, t_struct *global);
void	init_fork(t_struct *global, t_philo *philo);
void	philo(t_struct *global);

int	check_arg(char **av);
int	valid_or_not(char **av);
int	ft_atoi(char *str);

#endif
