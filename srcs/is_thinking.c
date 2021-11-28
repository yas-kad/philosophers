/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:28:24 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/27 22:28:26 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_thinking(t_philo *curr_philo, t_data *data)
{
	pthread_mutex_lock(&data->message);
	printf("\033[0;33m%ld		%d		is thinking\n\033[0m",
		(time_stamp() - data->starting_time), curr_philo->id);
	pthread_mutex_unlock(&data->message);
}
