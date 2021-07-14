/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 23:37:49 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/15 02:52:54 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static char	*ft_bit(char c)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(8));
	if (!ret)
		exit (0);
	ret[7] = 0;
	i = 6;
	while (c > 1)
	{
		ret[i] = (c % 2) + 48;
		c /= 2;
		i--;
	}
	ret[i] = (c % 2) + 48;
	i--;
	while (i >= 0)
	{
		ret[i] = 48;
		i--;
	}
	return (ret);
}

static void	send_term(int pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(50);
	}
}

static void	send_signal(int pid, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_bit(str[i]);
		j = 0;
		while (tmp[j])
		{
			if (tmp[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(50);
		}
		free(tmp);
		i++;
	}
	send_term(pid);
}

static void	check_arg(int argc, char **argv)
{
	if (argc != 3)
		exit (0);
	if (!is_num(argv[1]))
		exit (0);
	if (ft_atoi(argv[1]) == 0)
		exit (0);
	if (!check_str(argv[2]))
		exit (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*str;

	check_arg(argc, argv);
	pid = ft_atoi(argv[1]);
	i = 0;
	str = argv[2];
	send_signal(pid, str);
	return (0);
}
