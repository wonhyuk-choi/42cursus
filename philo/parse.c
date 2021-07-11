/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:18:15 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/12 00:14:21 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_is_string(const char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	ans;
	int				neg;

	ans = 0;
	neg = 1;
	while (ft_is_string(*nptr, "\t\n\r\v\f "))
		nptr++;
	if (nptr[0] == '-')
	{
		neg *= -1;
		nptr++;
	}
	else if (nptr[0] == '+')
		nptr++;
	while (ft_is_string(*nptr, "0123456789"))
	{
		ans = ans * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(neg * ans));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	check_args_validity(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_arg(t_status *status, int argc, char **argv)
{
	int	i;
	int	tmp;

	i = 1;
	while (argv[i])
	{
		tmp = check_args_validity(argv[i]);
		if (!tmp)
			return (-1);
		i++;
	}
	status->philo_num = ft_atoi(argv[1]);
	status->die_time = ft_atoi(argv[2]);
	status->eat_time = ft_atoi(argv[3]);
	status->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		status->max_eat = ft_atoi(argv[5]);
	else
		status->max_eat = -1;
	return (0);
}
