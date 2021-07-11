/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 01:00:14 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/11 23:58:17 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	do_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lunch);
	philo->last_meal = get_time();
	pthread_mutex_lock(philo->print);
	printf("%lums %d eating\n", get_ts(philo->ts), philo->philo_index);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_unlock(&philo->lunch);
	ft_sleep(philo->status->eat_time);
	philo->eat_count += 1;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (*philo->stat == 1)
		return (0);
	return (1);
}

int	do_sleep(t_philo *philo)
{
	if (*philo->stat == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %d sleep\n", get_ts(philo->ts), philo->philo_index);
	pthread_mutex_unlock(philo->print);
	ft_sleep(philo->status->sleep_time);
	if (*philo->stat == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %d thinking\n", get_ts(philo->ts), philo->philo_index);
	pthread_mutex_unlock(philo->print);
	return (1);
}

int	is_dead(t_philo *philo)
{
	if (*philo->stat == 1)
		return (1);
	pthread_mutex_lock(&philo->lunch);
	if ((long)(get_time() - philo->last_meal) >= philo->status->die_time)
	{
		pthread_mutex_unlock(&philo->lunch);
		if (*philo->stat == 0)
		{
			*philo->stat = 1;
			pthread_mutex_lock(philo->print);
			printf("%lums %d died\n", get_ts(philo->ts), philo->philo_index);
			pthread_mutex_unlock(philo->print);
		}
		return (1);
	}
	pthread_mutex_unlock(&philo->lunch);
	return (0);
}

int	take_fork(t_philo *philo, pthread_mutex_t *l_fork, \
	pthread_mutex_t *r_fork)
{
	if (*philo->stat == 1)
		return (0);
	pthread_mutex_lock(l_fork);
	if (*philo->stat == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %d take a fork\n", get_ts(philo->ts), philo->philo_index);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(r_fork);
	if (*philo->stat == 1)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%lums %d take a fork\n", get_ts(philo->ts), philo->philo_index);
	pthread_mutex_unlock(philo->print);
	return (1);
}

void	unlock_fork(pthread_mutex_t *fork, int	philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_unlock(&fork[i]);
		i++;
	}
}
