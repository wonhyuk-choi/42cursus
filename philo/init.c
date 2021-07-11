/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:22:25 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/11 00:33:39 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	*init_fork(t_status *status)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * status->philo_num);
	if (!fork)
		return (0);
	while (i < status->philo_num)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return (fork);
}

void	get_fork(t_philo *philo, int i, pthread_mutex_t *fork, int philo_num)
{
	if (philo_num == 1)
	{
		philo->l_fork = &fork[0];
		philo->r_fork = &fork[0];
	}
	else if (i == 0)
	{
		philo->l_fork = &fork[philo_num - 1];
		philo->r_fork = &fork[0];
	}
	else
	{
		philo->l_fork = &fork[i - 1];
		philo->r_fork = &fork[i];
	}
}

void	set_philo(t_philo *philo, t_status *status, pthread_mutex_t *fork, \
	pthread_mutex_t *print)
{
	int	i;

	i = 0;
	while (i < status->philo_num)
	{
		philo[i].philo_index = i + 1;
		philo[i].eat_count = 0;
		philo[i].status = status;
		philo[i].print = print;
		pthread_mutex_init(&philo[i].lunch, NULL);
		get_fork(&philo[i], i, fork, status->philo_num);
		i++;
	}
}
