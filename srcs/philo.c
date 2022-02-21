/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:31:08 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/21 16:08:39 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	good_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*who_is_dead(void *p_philo)
{
	t_philo		*philo;
	t_struct	*n_global;

	philo = (t_philo *)p_philo;
	n_global = philo->global;
	while (philo->global->state == 0 && philo->stop == 0)
	{
		// printf("Philo id %d | last meal == %ld\n", philo->index, good_time() - philo->last_meal);
		if ((good_time() - philo->last_meal) > n_global->base.t_to_die)
		{
			display(philo, "died");
			pthread_mutex_lock(&philo->state_mutex);
			philo->stop = 1;
			philo->global->state = 1;
			pthread_mutex_unlock(&philo->state_mutex);
			break ;
		}
	}
	return (NULL);
}

void	*philosophers(void *p_philo)
{
	t_philo		*philo;
	t_struct	*n_global;
	pthread_t	death;

	philo = (t_philo *)p_philo;
	n_global = philo->global;
	pthread_create(&death, NULL, &who_is_dead, philo);
	pthread_detach(death);
	// if (philo->index % 2 == 0)
	// 	usleep(n_global->base.t_to_eat * 1000);
	philo->index % 2 ? 0 : usleep(n_global->base.t_to_eat * 1000);
	while (philo->global->state == 0 && philo->stop == 0)
	{
		eat(philo);
		if (n_global->base.n_time_eat
			&& philo->t_he_eat == n_global->base.n_time_eat)
			philo->stop = 1;
		display(philo, "is sleeping");
		usleep(n_global->base.t_to_sleep * 1000);
		display(philo, "is thinking");
	}
	return (NULL);
}

void	go_philo(t_struct *global, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < global->base.n_philo)
	{
		pthread_create(&philo[i].t, NULL, &philosophers, &philo[i]);
		usleep(10);
		i++;
	}
	i = 0;
	while (i < global->base.n_philo)
	{
		pthread_join(philo[i].t, NULL);
		i++;
	}
}

void	finished(t_struct *global, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo[i].stdout_mutex);
	pthread_mutex_destroy(&philo[i].state_mutex);
	while (i < global->base.n_philo)
	{
		pthread_mutex_destroy(philo[i].left_fork);
		free(philo[i].left_fork);
		i++;
	}
	free(philo);
}
