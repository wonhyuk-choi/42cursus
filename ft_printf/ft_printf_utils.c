/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:05:10 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/07 18:01:16 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_len(long long num, int len)
{
	return (num ? 1 + check_len(num / len, len) : 0);
}

char		*utoa(unsigned long long num, char base[16])
{
	int		len;
	char	*ret;
	int		base_len;

	base_len = 16;
	len = 1 + check_len(num / base_len, base_len);
	ret = malloc(len + 1);
	ret[len] = 0;
	while (len > 0)
	{
		len--;
		ret[len] = base[(num % base_len)];
		num = num / base_len;
	}
	return (ret);
}

void		join_zero(char **form_str, int num)
{
	char	*left;
	char	*right;

	left = save_str('0', num);
	right = *form_str;
	*form_str = join_str(left, right);
}

char		*save_str(char c, int count)
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

char		*join_str(char *left, char *right)
{
	char	*ret;

	ret = ft_strjoin(left, right);
	free(left);
	free(right);
	return (ret);
}
