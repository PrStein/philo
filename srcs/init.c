/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:56:38 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/06 23:20:23 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
