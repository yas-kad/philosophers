/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:42:57 by yait-kad          #+#    #+#             */
/*   Updated: 2021/11/22 16:42:59 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_print_error(char *str)
{
	printf("%s", str);
	return (ERROR);
}

int		ft_is_num(char *str)
{
	int i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (!ft_isdigit(str[++i]))
			return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse(int ac, char **argv, t_data *var)
{
	int i = 1;
	if (ac != 5 && ac != 6)
		return(ft_print_error("\033[0;31mError: number of argumments!!\n\033[0m"));
	while (argv[i])
	{
		if (ft_is_num(argv[i]) == 0)
			return(ft_print_error("\033[0;31mError: an argument is not a number!!\n\033[0m"));
		i++;
	}
	var->number_of_philosophers = ft_atoi(argv[1]);
	if (var->number_of_philosophers <= 0)
		return(ft_print_error("\033[0;31mError: number of philosophers invalid!!\n\033[0m"));
	var->time_to_die = ft_atoi(argv[2]);
	if (var->time_to_die <= 0)
		return(ft_print_error("\033[0;31mError: time to die invalid!!\n\033[0m"));
	var->time_to_eat = ft_atoi(argv[3]);
	if (var->time_to_eat <= 0)
		return(ft_print_error("\033[0;31mError: time to eat invalid!!\n\033[0m"));
	var->time_to_sleep = ft_atoi(argv[4]);
	if (var->time_to_sleep <= 0)
		return(ft_print_error("\033[0;31mError: time to sleep invalid!!\n\033[0m"));
	var->number_of_times_for_eating = 0;
	if (ac == 6)
	{
		var->number_of_times_for_eating = ft_atoi(argv[5]);
		if (var->number_of_times_for_eating <= 0)
			return(ft_print_error("\033[0;31mError: number of times for eating invalid!!\n\033[0m"));
	}
	return (SUCCESS);
}
