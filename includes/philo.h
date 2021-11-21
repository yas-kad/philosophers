/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:41:27 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/03 15:41:29 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct	s_data
{
	int				number_of_philosophers;
	int				number_of_times_for_eating;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*forks_mutexs;
	pthread_mutex_t	main_mutex;
	pthread_mutex_t message;
	long int		starting_time;
}				t_data;

typedef struct	s_philo
{
	int		id;
	long int 	life_time;
	t_data	*data;
}				t_philo;



int		ft_atoi(const char *str);
int		ft_parse(int ac, char **argv, t_data *var);

# define SUCCESS 1
# define ERROR -1

# endif
