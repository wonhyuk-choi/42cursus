/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:05:10 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/01 19:20:16 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*save_str(char c, int count)
{
	char	*str;

	str = malloc(count + 1);
	str[count] = 0;
	while (count > 0)
	{
		count--;
		str[count] = c;
	}
	return (str);
}

char	*join_str(char *left, char *right)
{
	char	*ret;

	ret = ft_strjoin(left, right);
	free(left);
	free(right);
	return (ret);
}
