/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eating_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:51:15 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 23:51:17 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*num_of_eating(void *philo)
{
	t_philo	*curr_philo;
	int		eating_num;

	curr_philo = (t_philo *)philo;
	eating_num = curr_philo->data->number_of_times_for_eating
		* curr_philo->data->number_of_philosophers;
	while (1)
	{
		if (curr_philo->data->number_of_eating >= eating_num)
			pthread_mutex_unlock(&curr_philo->data->main_mutex);
		usleep(100);
	}
}
