/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:27:44 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/06 01:03:44 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_philo(t_status *status, int argc, char **argv)
{
	status->philo_num = argv[1];
	status->die_time = argv[2];
	status->eat_time = argv[3];
	status->sleep_time = argv[4];
	if (argc == 6)
		status->eat_count = argv[5];
	else
		status->eat_count = 0;
}

int	main(int argc, char **argv)
{
	t_status	*status;

	if (!(argc == 5 || argc == 6))
		return (-1);
	//init 필로소퍼
	if (!(init_philo(status, argc, argv)))
		return (-1);
	return (0);
}