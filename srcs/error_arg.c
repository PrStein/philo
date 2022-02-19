/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:41:06 by sadjigui          #+#    #+#             */
/*   Updated: 2022/02/19 20:23:26 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	valid_or_not(char **av)
{
	int	i;

	i = check_arg(av);
	if (i == 1)
		printf("Invalid arguments\n");
	return (i);
}

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	error_arg(int ac)
{
	if (ac < 5)
		printf("Missing arguments\n");
	else if (ac > 6)
		printf("Too many arguments\n");
}
