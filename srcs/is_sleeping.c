/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:28:14 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 22:28:15 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_sleeping(t_philo *curr_philo, t_data *data)
{
	pthread_mutex_lock(&data->message);
	printf("\033[0;35m%ld		%d		is sleeping\n\033[0m",
		(time_stamp() - data->starting_time), curr_philo->id);
	pthread_mutex_unlock(&data->message);
	usleep(data->time_to_sleep * 1000);
}
