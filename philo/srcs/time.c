/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:44:20 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/12 00:00:34 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned long	get_ts(struct timeval ts)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long)(tv.tv_sec * 1000 + tv.tv_usec / 1000)
			- (ts.tv_sec * 1000 + ts.tv_usec / 1000));
}

int	get_time(void)
{
	struct timeval	tp;
	unsigned int	milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	ft_sleep(int ms)
{
	int	curr;
	int	end;

	curr = get_time();
	end = curr + ms;
	// printf("time %u || %u\n", get_time(), end);
	while (get_time() <= end)
		usleep(100);
}
