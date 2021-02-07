/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:19:05 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/07 20:39:00 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_string(char **form_str, int count, t_format *form_info)
{
	char	*left;
	char	*right;

	if (form_info->minus)
	{
		left = *form_str;
		right = save_str(' ', count);
	}
	else
	{
		if (form_info->zero)
			left = save_str('0', count);
		else
			left = save_str(' ', count);
		right = *form_str;
	}
	*form_str = join_str(left, right);
}

void		check_form_c(char **form_str, char c, t_format *form_info)
{
	int		count;

	form_info->null = !c;
	if (c == '\0' && form_info->minus)
	{
		ft_putchar_fd(0, 1);
		form_info->null = -1;
	}
	*form_str = malloc(2);
	(*form_str)[0] = c;
	(*form_str)[1] = 0;
	count = form_info->width - 1;
	if (count > 0)
		check_string(form_str, count, form_info);
}

void		check_form_s(char **form_str, t_format *form_info)
{
	int		count;

	*form_str = va_arg(form_info->ap, char*);
	if (*form_str == 0)
		*form_str = "(null)";
	if (form_info->dot > -1)
		*form_str = ft_substr(*form_str, 0, form_info->dot);
	else
		*form_str = ft_strjoin(*form_str, "");
	count = form_info->width - (int)ft_strlen(*form_str);
	if (count > 0)
		check_string(form_str, count, form_info);
}
