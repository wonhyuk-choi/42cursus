/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:51:27 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/05 18:35:46 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfr.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*big_tmp;
	char	*little_tmp;

	if (!*little)
		return ((char*)big);
	little_len = ft_strlen(little);
	if (!ft_strlen(big) || len < little_len)
		return (0);
	len = len - little_len - 1;
	while (len-- && *big != '\0')
	{
		big_tmp = (char*)big;
		little_tmp = (char*)little;
		while (*little_tmp && *big_tmp == little_tmp)
		{
			little_tmp++;
			big_tmp++;
		}
		if (*little_tmp == 0)
			return ((char*)big);
		big++;
	}
	return (0);
}
