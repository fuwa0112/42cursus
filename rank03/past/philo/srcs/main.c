/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:07:19 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/31 17:27:53 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	args_erro(int signal)
{
	write(2, "Error: Invalid array usage.\n", 28);
	write(2, "Usage: please follow the format below.\n", 39);
	write(2, "./philos [Philosophers] [time_to_die] [time_to_eat] ", 53);
	write(2, "[time_to_sleep] ([times_each_philosopher_must_eat])\n", 51);
	exit(signal);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 0;
	if (argc < 5 || argc > 6)
		args_erro(1);
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
			args_erro(1);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			args_erro(1);
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			args_erro(1);
	}
}

int	main(int argc, char **argv)
{
	t_philo		philos[PHILO_MAX_COUNT];
	t_mutex		forks[PHILO_MAX_COUNT];
	t_engine	engine;

	check_args(argc, argv);
	init_engine(&engine, philos, forks);
	init_forks(&engine, forks, ft_atoi(argv[1]));
	init_philos(&engine, philos, forks, argv);
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, NULL, philos[0].philo_count, 0);
	return (0);
}
