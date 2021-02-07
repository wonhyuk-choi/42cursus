/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:03:11 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/07 18:00:48 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_join_zero(char **form_str, t_format *form_info, int flag, int len)
{
	int			count;
	char		*left;
	char		*right;

	if (form_info->dot >= 0)
	{
		count = form_info->dot - len;
		if (count > 0)
		{
			left = save_str('0', count);
			right = *form_str;
			*form_str = join_str(left, right);
		}
	}
	else
	{
		count = form_info->width - len;
		if (!form_info->minus && form_info->zero && count > 0)
		{
			left = save_str('0', count - flag);
			right = *form_str;
			*form_str = join_str(left, right);
		}
	}
}

static void	d_minus(char **form_str)
{
	char		*tmp;

	tmp = *form_str;
	*form_str = ft_strjoin("-", *form_str);
	free(tmp);
}

static void	join_space(char **form_str, t_format *form_info)
{
	int			count;
	char		*left;
	char		*right;

	count = form_info->width - ft_strlen(*form_str);
	if (count > 0)
	{
		if (form_info->minus)
		{
			left = *form_str;
			right = save_str(' ', count);
		}
		else
		{
			left = save_str(' ', count);
			right = *form_str;
		}
		*form_str = join_str(left, right);
	}
}

static void	check_diform(char **form_str, t_format *form_info, int flag)
{
	int			len;

	len = (int)ft_strlen(*form_str);
	d_join_zero(form_str, form_info, flag, len);
	if (flag == 1)
		d_minus(form_str);
	join_space(form_str, form_info);
}

void		check_form_di(char **form_str, t_format *form_info)
{
	long long	num;
	int			flag;
	char		base[10];

	num = 0;
	while (num < 10)
	{
		base[num] = num + 48;
		num++;
	}
	num = va_arg(form_info->ap, int);
	flag = 0;
	if (num < 0)
		flag = 1;
	if (flag > 0)
		*form_str = dtoa(-num, base);
	else
		*form_str = dtoa(num, base);
	if (num == 0 && form_info->dot == 0)
		(*form_str)[0] = 0;
	check_diform(form_str, form_info, flag);
}
