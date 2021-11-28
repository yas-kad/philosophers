/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:51:02 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 23:51:05 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*mlkm(void *philo)
{
	t_philo	*c_philo;

	c_philo = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&c_philo->eating_mutex);
		pthread_mutex_lock(&c_philo->data->death_mutex);
		if (c_philo->data->is_sim_over == TRUE)
			break ;
		if (time_stamp() > c_philo->life_time)
		{
			c_philo->data->is_sim_over = TRUE;
			pthread_mutex_lock(&c_philo->data->message);
			printf("\033[0;36m%ld		%d		died\n\033[0m",
				(time_stamp() - c_philo->data->starting_time), c_philo->id);
			pthread_mutex_unlock(&c_philo->data->main_mutex);
			break ;
		}
		pthread_mutex_unlock(&c_philo->eating_mutex);
		pthread_mutex_unlock(&c_philo->data->death_mutex);
		usleep(500);
	}
	return (NULL);
}
