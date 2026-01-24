/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:29:50 by thitoe            #+#    #+#             */
/*   Updated: 2026/01/25 02:52:16 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_data(t_philo_data *data, char **av)
{
	data->number_of_philo = atoicheck(av[1]);
	data->time_to_die = atoicheck(av[2]);
	data->time_to_eat = atoicheck(av[3]);
	data->time_to_sleep = atoicheck(av[4]);
	if (av[5])
		data->meals = atoicheck(av[5]);
	else
		data->meals = -1;
	data->dead_flag = 0;
	data->eat_flag = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	data->start_time = get_current_time();
}

void	init_forks(pthread_mutex_t *forks, int number_of_philo)
{
	int	i;

	i = 0;
	while (i < number_of_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philos(t_philosopher *philosophers, t_philo_data *data,
		pthread_mutex_t *forks)
{
	int	i;

	init_forks(forks, data->number_of_philo);
	i = 0;
	while (i < data->number_of_philo)
	{
		philosophers[i].philo_id = i + 1;
		philosophers[i].meal_counter = 0;
		philosophers[i].last_meal_time = data->start_time;
		philosophers[i].data = data;
		if (i % 2 == 0)
		{
			philosophers[i].left_fork = &forks[i];
			philosophers[i].right_fork = &forks[(i + 1)
				% data->number_of_philo];
		}
		else
		{
			philosophers[i].left_fork = &forks[(i + 1) % data->number_of_philo];
			philosophers[i].right_fork = &forks[i];
		}
		i++;
	}
}

void	thread_create_error(void)
{
	write(2, "Error creating thread\n", 22);
	return ;
}

void	init_threads(t_philosopher *philosophers, t_philo_data *data)
{
	pthread_t	monitoring;
	int			i;

	i = 0;
	if (pthread_create(&monitoring, NULL, monitor, philosophers) != 0)
		thread_create_error();
	while (i < data->number_of_philo)
	{
		if (pthread_create(&philosophers[i].thread, NULL,
				philosopher_routine, &philosophers[i]) != 0)
			thread_create_error();
		i++;
	}
	i = 0;
	pthread_join(monitoring, NULL);
	while (i < data->number_of_philo)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}
