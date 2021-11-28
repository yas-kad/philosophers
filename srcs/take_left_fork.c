/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_left_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:27:35 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 22:27:38 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_left_fork(t_philo *curr_philo, t_data *data)
{
	pthread_mutex_lock(&data->forks_mutexs[curr_philo->id - 1]);
	pthread_mutex_lock(&data->message);
	printf("%ld		%d		has taken a left fork\n",
		(time_stamp() - data->starting_time), curr_philo->id);
	pthread_mutex_unlock(&data->message);
}
