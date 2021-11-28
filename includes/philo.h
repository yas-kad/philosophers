/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:48:12 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/22 16:48:14 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define FALSE 0
# define TRUE 1

typedef struct s_data
{
	int				number_of_philosophers;
	int				number_of_times_for_eating;
	int				number_of_eating;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*forks_mutexs;
	pthread_mutex_t	main_mutex;
	pthread_mutex_t	message;
	pthread_mutex_t	death_mutex;
	long int		starting_time;
	int				is_sim_over;
}				t_data;

typedef struct s_philo
{
	int				id;
	long int		life_time;
	pthread_mutex_t	eating_mutex;
	t_data			*data;
}				t_philo;

int		ft_atoi(const char *str);
int		ft_parse(int ac, char **argv, t_data *var);
void	initial_mutexes(t_data *data, t_philo *philo);
void	initial_philo(t_philo **philo, t_data *data);
long	time_stamp(void);
void	*mlkm(void *philo);
void	*num_of_eating(void *philo);
void	*sim(void *philo);
void	take_left_fork(t_philo *curr_philo, t_data *data);
void	take_right_fork(t_philo *curr_philo, t_data *data);
void	is_eating(t_philo *curr_philo, t_data *data);
void	is_sleeping(t_philo *curr_philo, t_data *data);
void	is_thinking(t_philo *curr_philo, t_data *data);
void	destroy_mutexes(t_philo *philo, t_data *data);

# define SUCCESS 1
# define ERROR -1

#	endif
