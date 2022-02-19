/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:26:26 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/19 20:09:52 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_time {
	int	n_philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	n_time_eat;
}			t_time;

typedef struct s_struct {
	t_time	base;
	int		state;
	long	start;
}			t_struct;

typedef struct s_philo {
	pthread_t		t;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	stdout_mutex;
	pthread_mutex_t	state_mutex;
	int				index;
	int				t_he_eat;
	int				state;
	int				stop;
	long			last_meal;
	t_struct		*global;
}			t_philo;

t_philo	*init_philo(t_struct *global);

void	error_arg(int ac);
void	init_time(int ac, char **av, t_struct *global);
void	init_fork(t_struct *global, t_philo *philo);
void	philo(t_struct *global);
void	display(t_philo *philo, char *msg);
void	eat(t_philo *philo);
void	finished(t_struct *global, t_philo *philo);
void	go_philo(t_struct *global, t_philo *philo);

int		check_arg(char **av);
int		valid_or_not(char **av);
int		ft_atoi(char *str);

long	good_time(void);

#endif
