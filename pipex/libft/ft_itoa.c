/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:51:27 by wonchoi           #+#    #+#             */
/*   Updated: 2021/03/21 20:04:18 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_check(int n)
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

char		*ft_itoa(int n)
{
	char		*ret;
	long long	len;
	long long	save;

	len = ft_len_check(n);
	save = n;
	if (n <= 0)
	{
		save = -save;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret == 0)
		return (0);
	ret[len] = 0;
	while (len > 0)
	{
		ret[len - 1] = (save % 10) + '0';
		save = save / 10;
		len--;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
