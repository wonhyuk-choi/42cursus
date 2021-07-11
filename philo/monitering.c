/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:37:21 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/12 00:51:33 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_meal(t_philo *philo, int philo_num, int max_eat)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (philo[i].eat_count < max_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*life(void	*tmp_philo)
{
	t_philo		*philo;

	philo = (t_philo *)tmp_philo;
	if (philo->philo_index % 2)
		ft_sleep(2);
	while (*philo->stat == 0)
	{
		if (!take_fork(philo, philo->l_fork, philo->r_fork))
			break ;
		if (!do_eat(philo))
			break ;
		if (philo->eat_count == philo->status->max_eat)
			break ;
		if (!do_sleep(philo))
			break ;
	}
	pthread_mutex_destroy(&philo->lunch);
	return (NULL);
}

int	check_death(t_philo *philo, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (is_dead(&philo[i]))
			return (1);
		i++;
	}
	return (0);
}

int	monitering(t_status *status, t_philo *philo, int philo_num, \
	pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (*philo->stat == 0)
	{
		ft_sleep(4);
		check_death(philo, philo_num);
		if (*philo->stat == 0 && status->max_eat > 0 && \
			check_meal(philo, philo_num, status->max_eat))
		{
			*philo->stat = 1;
			ft_sleep(5);
			printf("All philosopher ate!\n");
		}
	}
	while (i < philo_num)
	{
		if (i == 0 && *philo->stat == 1)
			unlock_fork(fork, philo_num);
		if (pthread_join(philo[i].thread, NULL))
			return (0);
		i++;
	}
	free(philo);
	return (1);
}
