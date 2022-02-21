/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_and_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:54:57 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/21 15:49:48 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->stdout_mutex);
	if (philo->global->state == 0)
		printf("%.4ld ms: Philo number %d %s\n",
			good_time() - philo->global->start, philo->index, msg);
	pthread_mutex_unlock(&philo->stdout_mutex);
}

void	eat(t_philo *philo)
{
	// if (philo->index % 2 == 0)
	// {
		// usleep(philo->global->base.t_to_eat * 1000);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	// }
	// else if (philo->index % 2 != 0)
	// {
	// 	pthread_mutex_lock(philo->left_fork);
	// 	pthread_mutex_lock(philo->right_fork);
	// }
	display(philo, "has taken the forks");
	philo->last_meal = good_time();
	display(philo, "is eating");
	usleep(philo->global->base.t_to_eat * 1000);
	if (philo->global->base.n_time_eat)
		philo->t_he_eat++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
