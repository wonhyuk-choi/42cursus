/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:15:46 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/04 20:35:55 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_len(long long num, int len)
{
	int ret;

	if (num > 0)
		ret = 1 + check_len(num / len, len);
	else
		ret = 0;
	return (ret);
}

static void	*dtoa(unsigned long long num, char base[10])
{
	int					len;
	int					base_len;
	char				*ret;
	
	base_len = 10;
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

static void	check_uform(char **form_str, t_format *form_info)
{
}

void	check_form_u(char **form_str, t_format *form_info)
{
	unsigned int		num;
	char				base[10];

	num = 0;
	while (num < 10)
	{
		base[num] = num + 48;
		num++;
	}
	num = va_arg(form_info->ap, unsigned int);
	*form_str = dtoa(num, base);
	if (num == 0 & form_info->dot == 0)
		(*form_str)[0] = 0;
	check_uform(form_str, form_info);
}
