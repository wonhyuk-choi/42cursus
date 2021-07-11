/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:27:44 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/11 23:57:41 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	start_thread(t_status *status, pthread_mutex_t	*fork, \
	pthread_mutex_t *print)
{
	t_philo			*philo;
	int				i;
	int				stat;
	struct timeval	timestamp;

	i = 0;
	stat = 0;
	philo = malloc(sizeof(t_philo) * status->philo_num);
	if (!philo)
		return (0);
	set_philo(philo, status, fork, print);
	gettimeofday(&timestamp, NULL);
	while (i < status->philo_num)
	{
		philo[i].stat = &stat;
		philo[i].ts = timestamp;
		philo[i].last_meal = get_time();
		if (pthread_create(&philo[i].thread, NULL, &life, &philo[i]))
			return (0);
		i++;
	}
	return (monitering(status, philo, status->philo_num, fork));
}

void	fork_destroy(pthread_mutex_t *fork, t_status *status)
{
	int	i;

	i = 0;
	while (i < status->philo_num)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	free(fork);
}

int	main(int argc, char **argv)
{
	t_status		status;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;

	if (argc < 5 || argc > 6)
		return (-1);
	if (parse_arg(&status, argc, argv) == -1)
		return (-1);
	fork = init_fork(&status);
	pthread_mutex_init(&print, NULL);
	start_thread(&status, fork, &print);
	fork_destroy(fork, &status);
	pthread_mutex_destroy(&print);
	return (0);
}
