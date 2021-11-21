/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:40:49 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/03 15:40:52 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <time.h>
#include <sys/time.h>

long time_stamp()
{
	struct timeval currTime;
	gettimeofday(&currTime, NULL);

	//printf("curr time in s : %ld\nadditional time in us : %d\n", currTime.tv_sec, currTime.tv_usec);
	return (currTime.tv_sec * 1000) + (currTime.tv_usec / 1000);
}

void *azrael(void *philo)
{
	t_philo *curr_philo;

	curr_philo = (t_philo*)philo;

	while (1)
	{
		// printf("%ld | %ld \n", curr_philo->life_time, time_stamp());
		if (time_stamp() > curr_philo->life_time)
		{
			pthread_mutex_lock(&curr_philo->data->message);
			printf("%ld %d is death\n",time_stamp() - curr_philo->data->starting_time ,curr_philo->id);
			pthread_mutex_unlock(&curr_philo->data->main_mutex);
		}
		usleep(100);
	}
}


void *simulation(void *philo_ptr)
{
	t_data	*data;
	t_philo *curr_philo;

	curr_philo = (t_philo *)philo_ptr;
	data = curr_philo->data;
	pthread_t malakMaout;


	pthread_create(&malakMaout, NULL, azrael, curr_philo);

	while (1)
	{
		
		pthread_mutex_lock(&data->message);
		// printf("%ld ",time_stamp() - data->starting_time);
		printf("%ld %d is thinking\n",time_stamp() - curr_philo->data->starting_time ,curr_philo->id);
		pthread_mutex_unlock(&data->message);
		
		pthread_mutex_lock(&data->forks_mutexs[curr_philo->id - 1]);
		pthread_mutex_lock(&data->message);
		// printf("%ld ",time_stamp() - curr_philo->data->starting_time);
		printf("%ld %d has taken a fork\n", time_stamp() - curr_philo->data->starting_time, curr_philo->id);
		pthread_mutex_unlock(&data->message);
	
		pthread_mutex_lock(&data->forks_mutexs[curr_philo->id % curr_philo->data->number_of_philosophers]);
		pthread_mutex_lock(&data->message);
		// printf("%ld ",time_stamp() - data->starting_time);
		printf("%ld %d has taken a fork\n", time_stamp() - curr_philo->data->starting_time, curr_philo->id);
		pthread_mutex_unlock(&data->message);

		pthread_mutex_lock(&data->message);
		curr_philo->life_time = time_stamp() +  data->time_to_die;
		printf("%ld %d is eating\n",time_stamp() - curr_philo->data->starting_time , curr_philo->id);
		pthread_mutex_unlock(&data->message);
		usleep(data->time_to_eat * 1000);
		// sleep(1);
		pthread_mutex_unlock(&data->forks_mutexs[curr_philo->id - 1]);
		pthread_mutex_unlock(&data->forks_mutexs[curr_philo->id % curr_philo->data->number_of_philosophers]);
		pthread_mutex_lock(&data->message);
		// printf("%ld ",time_stamp() - curr_philo->data->starting_time);
		printf("%ld %d is sleeping\n", time_stamp() - curr_philo->data->starting_time, curr_philo->id);
		pthread_mutex_unlock(&data->message);
		usleep(data->time_to_sleep * 1000);
	}
	// return (NULL);
}

int main(int ac, char **argv)
{

	t_philo *philo;
	t_data data;
	if (ft_parse(ac, argv, &data) == ERROR)
		return (0);

	///creating philos
	philo = malloc(sizeof(t_philo) * data.number_of_philosophers);
	for (int i = 0; i < data.number_of_philosophers; i++)
	{
		philo[i].id = i + 1;
		philo[i].data = &data;
	}

	//creating forks_mutexes
	data.forks_mutexs = malloc(sizeof(pthread_mutex_t) * data.number_of_philosophers);
	for (int i = 0; i < data.number_of_philosophers; i++)
	{
		pthread_mutex_init(&data.forks_mutexs[i], NULL);
	}
	pthread_mutex_init(&data.message, NULL);
	pthread_mutex_init(&data.main_mutex, NULL);
	//creating threads
	data.starting_time = time_stamp();
	printf("time = %ld\n",data.starting_time);
	pthread_t id;
	pthread_mutex_lock(&data.main_mutex);
	for (int i = 0; i < data.number_of_philosophers; i++)
	{
		philo[i].life_time = time_stamp() + data.time_to_die;
		// exit(1);
		pthread_create(&id, NULL, simulation, &philo[i]);
		usleep(100);
	}
	pthread_mutex_lock(&data.main_mutex);
	// pthread_mutex_unlock(&data.main_mutex);
	return 0;
}
