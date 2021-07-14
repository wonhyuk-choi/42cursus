/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 00:14:19 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/15 02:52:59 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	ft_len(int n)
{
	long long	len;
	long long	num;

	num = n;
	len = 0;
	if (num < 0)
		num = num * -1;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;

	i = ft_len(n);
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	dst[i--] = 0;
	if (n < 0)
	{
		dst[0] = 45;
		dst[i] = (n % 10) * (-1) + 48;
		n = (n / 10) * (-1);
		if (n == 0)
			return (dst);
		i--;
	}
	while ((n / 10) > 0)
	{
		dst[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	dst[i] = n + 48;
	return (dst);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd != 0 && s != 0)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
