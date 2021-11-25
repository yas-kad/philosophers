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

long  time_stamp()
{
	struct timeval curr_time;
	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}

void	initial_mutexes(t_data *data)
{
	int i;

	i = 0;
	data->forks_mutexs = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks_mutexs[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->main_mutex, NULL);
	pthread_mutex_init(&data->message, NULL);
}

void	*mlkm(void *philo)
{
	t_philo *c_philo;

	c_philo = (t_philo *)philo;
	
	while (1)
	{
		if (time_stamp() > c_philo->life_time)
		{
			pthread_mutex_lock(&c_philo->data->message);
			printf("\033[0;36m%ld		%d		died\n\033[0m", (time_stamp() - c_philo->data->starting_time), c_philo->id);
			pthread_mutex_unlock(&c_philo->data->main_mutex);
		}
		usleep(100);
	}
	
}

void	*num_of_eating(void *philo)
{
	t_philo * curr_philo;
	int		eating_num;

	curr_philo = (t_philo *)philo;
	eating_num = curr_philo->data->number_of_times_for_eating * curr_philo->data->number_of_philosophers;
	while (1)
	{
		if (curr_philo->data->number_of_eating >= eating_num)
			pthread_mutex_unlock(&curr_philo->data->main_mutex);
		usleep(100);
	}
	
}

void	*sim(void *philo)
{
	t_philo *curr_philo;
	t_data *data;
	pthread_t az;
	pthread_t ne;

	curr_philo = (t_philo *)philo;
	data = curr_philo->data;

	pthread_create(&az, NULL, mlkm, curr_philo);
	if (data->number_of_times_for_eating != 0)
		pthread_create(&ne, NULL, num_of_eating, philo);
	while (1)
	{

		pthread_mutex_lock(&data->forks_mutexs[curr_philo->id - 1]);
		pthread_mutex_lock(&data->message);
		printf("%ld		%d		has taken a left fork\n", (time_stamp() - data->starting_time), curr_philo->id);
		pthread_mutex_unlock(&data->message);

		pthread_mutex_lock(&data->forks_mutexs[curr_philo->id % data->number_of_philosophers]);
		pthread_mutex_lock(&data->message);
		printf("%ld		%d		has taken a right fork\n", (time_stamp() - data->starting_time), curr_philo->id);
		pthread_mutex_unlock(&data->message);

		pthread_mutex_lock(&data->message);
		curr_philo->life_time = time_stamp() + data->time_to_die;
		printf("\033[0;32m%ld		%d		is eating\n\033[0m", (time_stamp() - data->starting_time), curr_philo->id);
		data->number_of_eating++;
		pthread_mutex_unlock(&data->message);
		usleep(data->time_to_eat * 1000);

		pthread_mutex_unlock(&data->forks_mutexs[curr_philo->id - 1]);
		pthread_mutex_unlock(&data->forks_mutexs[curr_philo->id % data->number_of_philosophers]);

		pthread_mutex_lock(&data->message);
		printf("\033[0;35m%ld		%d		is sleeping\n\033[0m", (time_stamp() - data->starting_time), curr_philo->id);
		pthread_mutex_unlock(&data->message);
		usleep(data->time_to_sleep * 1000);

		pthread_mutex_lock(&data->message);
		printf("\033[0;33m%ld		%d		is thinking\n\033[0m", (time_stamp() - data->starting_time), curr_philo->id);
		pthread_mutex_unlock(&data->message);

	}
}

void	initial_philo(t_philo **philo, t_data *data)
{
	int i;

	i = 0;
	(*philo) = malloc(sizeof(t_philo) * data->number_of_philosophers);
	while (i <= data->number_of_philosophers)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].data = data;
		i++;
	}
	
}

void	create_philo(t_philo *philo, t_data *data)
{
	int i;

	i = 0;
	pthread_t id;
	while (i < data->number_of_philosophers)
	{
		philo[i].life_time = time_stamp() + data->time_to_die;
		pthread_create(&id, NULL, sim, &philo[i]);
		i++;
		usleep(100);
	}
}

int main(int ac, char **argv)
{
	int i;
	t_philo *philo;
	t_data data;

	i = 0;
	if (ft_parse(ac, argv, &data) == ERROR)
		return(0);

	initial_mutexes(&data);
	pthread_mutex_lock(&data.main_mutex);
	
	data.starting_time = time_stamp();
	data.number_of_eating = 0;

	initial_philo(&philo, &data);
	create_philo(philo, &data);

	pthread_mutex_lock(&data.main_mutex);
	return 0;
}
