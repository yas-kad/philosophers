/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:45:08 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 23:45:14 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	initial_mutexes(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->forks_mutexs = malloc(sizeof(pthread_mutex_t) \
		* data->number_of_philosophers);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks_mutexs[i], NULL);
		pthread_mutex_init(&philo[i].eating_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&data->main_mutex, NULL);
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
}

void	initial_philo(t_philo **philo, t_data *data)
{
	int	i;

	i = 0;
	(*philo) = malloc(sizeof(t_philo) * data->number_of_philosophers);
	while (i < data->number_of_philosophers)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].data = data;
		i++;
	}
}
