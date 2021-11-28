/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:53:34 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 23:53:35 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*sim(void *philo)
{
	t_philo		*curr_philo;
	t_data		*data;
	pthread_t	az;

	curr_philo = (t_philo *)philo;
	data = curr_philo->data;
	pthread_create(&az, NULL, mlkm, curr_philo);
	while (1)
	{
		if (data->is_sim_over == TRUE)
			break ;
		take_left_fork(curr_philo, data);
		take_right_fork(curr_philo, data);
		is_eating(curr_philo, data);
		pthread_mutex_unlock(&data->forks_mutexs[curr_philo->id - 1]);
		pthread_mutex_unlock(&data->forks_mutexs[curr_philo->id
			% data->number_of_philosophers]);
		is_sleeping(curr_philo, data);
		is_thinking(curr_philo, data);
	}
	return (NULL);
}
