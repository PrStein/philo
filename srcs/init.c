/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:56:38 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/14 16:44:50 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_fork(t_struct *global, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < global->base.n_philo)
	{
		philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].left_fork)
			return ;
		i++;
	}
	i = 0;
	while (i < global->base.n_philo)
	{
		philo[i].right_fork = philo[(i + 1) % global->base.n_philo].left_fork;
		i++;
	}
}

t_philo	*init_philo(t_struct *global)
{
	t_philo *philo;
	int i;

	philo = malloc(sizeof(t_philo) * global->base.n_philo);
	if (!philo)
		return (NULL);
	init_fork(global, philo);
	i = 0;
	while (i < global->base.n_philo)
	{
		philo[i].index = i + 1;
		philo[i].t_he_eat = 0;
		philo[i].state = 0;
		i++;
	}
	return (philo);
}

int	ft_atoi(char *str)
{
	int		i;
	long	result;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result);
}

void	init_time(char **av, t_struct *global)
{
	global->base.n_philo = ft_atoi(av[1]);
	global->base.t_to_die = ft_atoi(av[2]);
	global->base.t_to_eat = ft_atoi(av[3]);
	global->base.t_to_sleep = ft_atoi(av[4]);
	global->base.n_time_eat = ft_atoi(av[5]);
}
