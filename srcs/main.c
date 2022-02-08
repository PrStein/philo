/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:26:22 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/06 23:30:51 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_struct global;

	if (ac == 6)
	{
		if (valid_or_not(av) == 1)
			return (0);
		init_time(av, &global);
		start_philo(&global);
	}
	else
		error_arg(ac);
	return(0);
}
