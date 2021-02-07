/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:03:04 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/05 17:01:38 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void check_detail_join(char **form_str, t_format *form_info, int num)
{
	char				*left;
	char				*right;

	if (form_info->minus)
	{
		left = *form_str;
		right = save_str(' ', num);
	}
	else
	{
		left = save_str(' ', num);
		right = *form_str;
	}
	*form_str = join_str(left, right);
}

static void check_pform(char **form_str, t_format *form_info)
{
	int					num;
	char				*tmp;

	num = form_info->dot - (int)ft_strlen(*form_str);
	if (num > 0)
		join_zero(form_str, num);
	tmp = *form_str;
	*form_str = ft_strjoin("0x", *form_str);
	free(tmp);
	num = form_info->width - (int)ft_strlen(*form_str);
	if (num > 0)
		check_detail_join(form_str, form_info, num);
}

void	check_form_p(char **form_str, t_format *form_info)
{
	unsigned long long	num;
	char				base[16];

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
	num = (unsigned long long)va_arg(form_info->ap, long long);
	*form_str = utoa(num, base);
	if (num == 0 && form_info->dot == 0)
		(*form_str)[0] = 0;
	check_pform(form_str, form_info);
}
