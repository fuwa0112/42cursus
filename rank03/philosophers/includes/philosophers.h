/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:16:33 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/29 20:16:34 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define uint64_t long long int

struct	s_configuration;
struct	s_philosopher;

typedef struct s_philosopher
{
	struct s_configuration		*conf;
	uint64_t					last_meal;
	int							sit;
	int							eat_count;
}			t_philo;

typedef struct s_configuration
{
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	t_philo				*philosophers;
	pthread_mutex_t		m;
	uint64_t			t_eat;
	uint64_t			t_die;
	uint64_t			t_sleep;
	int					philo_count;
	int					times_to_eat;
}		t_config;

t_config	*init_config(int ac, char **av);
void		*routine(void *arg);
void		wait_for_completion(t_config *conf);
long int	ft_atoi(const char *str);
uint64_t	gettimeofday_ms(void);
uint64_t	timestamp_in_ms(void);

#endif
