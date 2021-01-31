/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:31:00 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/31 17:14:49 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_flag(const char **form, t_format *form_info)
{
	char	c;

	c = **form;
	if (c == '-')
		form_info->minus = 1;
	else if (c == '0')
		form_info->zero = 1;
	else
		return (0);
	(*form)++;
	return (1);
}

int	read_width(const char **form, t_format *form_info)
{
	char	c;

	c = **form;
	if (c == '*')
	{
		form_info->width = va_arg(form_info->ap, int);
		if (form_info->width < 0)
		{
			form_info->minus = 1;
			form_info->width *= -1;
		}
		(*form)++;
	}
	else if (ft_isdigit(c))
	{
		form_info->width = ft_atoi(*form);
		while (ft_isdigit(c))
			(*form)++;
	}
	else
		return (0);
	return (1);
}

int	read_dot(const char **form, t_format *form_info)
{
	char c;

	if (**form != '.')
		return (0);
	c = *(++(*form));
	form_info->dot = 0;
	if (c == '*')
	{
		form_info->dot = va_arg(form_info->ap, int);
		(*form)++;
	}
	else if (ft_isdigit(c))
	{
		form_info->dot = ft_atoi(*form);
		while (ft_isdigit(c))
			(*form)++;
	}
	else
		return (0);
	return (1);
}
