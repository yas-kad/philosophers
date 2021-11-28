/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:42:19 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/22 16:42:22 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	create_philo(t_philo *philo, t_data *data)
{
	pthread_t	id;
	pthread_t	ne;
	int			i;

	i = 0;
	if (data->number_of_times_for_eating != 0)
		pthread_create(&ne, NULL, num_of_eating, philo);
	while (i < data->number_of_philosophers)
	{
		philo[i].life_time = time_stamp() + data->time_to_die;
		pthread_create(&id, NULL, sim, &philo[i]);
		pthread_detach(id);
		i++;
		usleep(100);
	}
}

int	main(int ac, char **argv)
{
	t_philo	*philo;
	t_data	data;

	if (ft_parse(ac, argv, &data) == ERROR)
		return (0);
	initial_philo(&philo, &data);
	initial_mutexes(&data, philo);
	data.starting_time = time_stamp();
	data.number_of_eating = 0;
	data.is_sim_over = FALSE;
	pthread_mutex_lock(&data.main_mutex);
	create_philo(philo, &data);
	pthread_mutex_lock(&data.main_mutex);
	destroy_mutexes(philo, &data);
	return (0);
}
