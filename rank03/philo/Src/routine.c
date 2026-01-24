/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:30:24 by thitoe            #+#    #+#             */
/*   Updated: 2026/01/25 02:44:30 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philosopher *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_message("is eating", philo, philo->philo_id);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	think(t_philosopher *philo)
{
	unsigned long	think_time;

	print_message("is thinking", philo, philo->philo_id);
	if (philo->data->number_of_philo % 2 == 1)
	{
		think_time = (philo->data->time_to_eat * 2)
			- philo->data->time_to_sleep;
		if (think_time > 0 && think_time < philo->data->time_to_die / 2)
			ft_usleep(think_time);
	}
}

static int	should_stop_simulation(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead_flag || philo->data->eat_flag)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (!should_stop_simulation(philo))
	{
		eat(philo);
		if (should_stop_simulation(philo))
			break ;
		think(philo);
		if (should_stop_simulation(philo))
			break ;
		dream(philo);
	}
	return (NULL);
}
