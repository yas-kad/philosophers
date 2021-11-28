/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_right_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:27:46 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 22:27:48 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_right_fork(t_philo *curr_philo, t_data *data)
{
	pthread_mutex_lock(&data->forks_mutexs[curr_philo->id
		% data->number_of_philosophers]);
	pthread_mutex_lock(&data->message);
	printf("%ld		%d		has taken a right fork\n",
		(time_stamp() - data->starting_time), curr_philo->id);
	pthread_mutex_unlock(&data->message);
}
