/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 23:37:56 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/15 02:53:09 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*creat_string(char status, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = malloc(2);
	if (!tmp)
		exit (EXIT_FAILURE);
	tmp[0] = status;
	tmp[1] = 0;
	if (str == 0)
	{
		str = malloc(2);
		if (str == 0)
			exit (EXIT_FAILURE);
		ft_strlcpy(str, tmp, 2);
	}
	else
	{
		tmp2 = str;
		str = ft_strjoin(str, tmp);
		if (str == 0)
			exit (EXIT_FAILURE);
		free(tmp2);
	}
	free(tmp);
	return (str);
}

static void	count(int sign)
{
	static int	count;
	static int	status;
	static char	*str;

	count++;
	if (sign == SIGUSR2)
	{
		status = status << 1;
		status += 1;
	}
	else
		status = status << 1;
	if (count == 7)
	{
		str = creat_string(status, str);
		if (status == 0)
		{
			ft_putstr_fd(str, 1);
			write(1, "\n", 1);
			free(str);
			str = 0;
		}
		count = 0;
		status = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*tmp;

	pid = getpid();
	tmp = ft_itoa(pid);
	if (tmp == 0)
		exit (EXIT_FAILURE);
	ft_putstr_fd(tmp, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, count);
	signal(SIGUSR2, count);
	while (1)
		pause();
	return (0);
}
