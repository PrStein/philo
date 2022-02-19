/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:26:22 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/19 20:37:57 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo(t_struct *global)
{
	int		i;
	t_philo	*philo;

	i = 0;
	global->start = good_time();
	philo = init_philo(global);
	if (global->base.n_philo == 1)
	{
		display(philo, "Has taken the forks");
		usleep(global->base.t_to_die * 1000);
		display(philo, "died");
		finished(global, philo);
		return ;
	}
	go_philo(global, philo);
	finished(global, philo);
}

int	main(int ac, char **av)
{
	t_struct	global;

	if (ac == 5 || ac == 6)
	{
		if (valid_or_not(av) == 1)
			return (0);
		init_time(ac, av, &global);
		philo(&global);
	}
	else
		error_arg(ac);
	return (0);
}
