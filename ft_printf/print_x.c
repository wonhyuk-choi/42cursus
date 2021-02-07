/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:08:39 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/05 15:27:40 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_detail_join(char **form_str, t_format *form_info, int num)
{
	char				*left;
	char				*right;
	char				c;

	if (form_info->minus)
	{
		left = *form_str;
		right = save_str(' ', num);
	}
	else
	{
		if (form_info->zero && form_info->dot < 0)
			c = '0';
		else
			c = ' ';
		left = save_str(c, num);
		right = *form_str;
	}
	*form_str = join_str(left, right);
}

static void	check_xform(char **form_str, t_format *form_info)
{
	int					num;

	num = form_info->dot - (int)ft_strlen(*form_str);
	if (num > 0)
		join_zero(form_str, num);
	num = form_info->width - (int)ft_strlen(*form_str);
	if (num > 0)
		check_detail_join(form_str, form_info, num);
}

void		check_form_x(char **form_str, t_format *form_info)
{
	char				base[16];
	unsigned long long	num;

	num = 0;
	while (num < 10)
	{
		base[num] = num + 48;
		num++;
	}
	while (num < 16)
	{
		base[num] = num + 87;
		num++;
	}
	num = va_arg(form_info->ap, unsigned int);
	*form_str = utoa(num, base);
	if (num == 0 && form_info->dot == 0)
		(*form_str)[0] = 0;
	check_xform(form_str, form_info);
}

void		check_form_lx(char **form_str, t_format *form_info)
{
	char				base[16];
	unsigned long long	num;

	num = 0;
	while (num < 10)
	{
		base[num] = num + 48;
		num++;
	}
	while (num < 16)
	{
		base[num] = num + 55;
		num++;
	}
	num = va_arg(form_info->ap, unsigned int);
	*form_str = utoa(num, base);
	if (num == 0 && form_info->dot == 0)
		(*form_str)[0] = 0;
	check_xform(form_str, form_info);
}
