/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:50:04 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 22:50:06 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_eating(t_philo *curr_philo, t_data *data)
{
	pthread_mutex_lock(&curr_philo->eating_mutex);
	pthread_mutex_lock(&data->message);
	printf("\033[0;32m%ld		%d		is eating\n\033[0m",
		(time_stamp() - data->starting_time), curr_philo->id);
	pthread_mutex_unlock(&data->message);
	data->number_of_eating++;
	usleep(data->time_to_eat * 1000);
	curr_philo->life_time = time_stamp() + data->time_to_die - data->time_to_eat;
	pthread_mutex_unlock(&curr_philo->eating_mutex);
}
