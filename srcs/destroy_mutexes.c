/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:26:12 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 23:26:14 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutexes(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks_mutexs[i]);
		pthread_mutex_destroy(&philo[i].eating_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->main_mutex);
	free(philo);
	philo = NULL;
	free(data->forks_mutexs);
	data->forks_mutexs = NULL;
	pthread_mutex_unlock(&data->message);
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->death_mutex);
}
