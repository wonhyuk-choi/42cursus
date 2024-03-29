/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:23:46 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/10 16:15:21 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_format_list(t_format *form)
{
	form->minus = 0;
	form->zero = 0;
	form->dot = -1;
	form->width = 0;
	form->type = 0;
	form->null = 0;
}

char		*check_form(t_format *form_info)
{
	char	*form_str;
	char	check;

	check = form_info->type;
	if (check == 'c')
		check_form_c(&form_str, va_arg(form_info->ap, int), form_info);
	else if (check == 's')
		check_form_s(&form_str, form_info);
	else if (check == 'd' || check == 'i')
		check_form_di(&form_str, form_info);
	else if (check == 'p')
		check_form_p(&form_str, form_info);
	else if (check == 'u')
		check_form_u(&form_str, form_info);
	else if (check == 'x')
		check_form_x(&form_str, form_info);
	else if (check == 'X')
		check_form_lx(&form_str, form_info);
	else
		check_form_c(&form_str, check, form_info);
	return (form_str);
}

static void	str_putchar(t_format *form_info, int *ret)
{
	char	*str;

	str = check_form(form_info);
	*ret += ft_strlen(str) + (form_info->null != 0);
	ft_putstr_fd(str, 1);
	free(str);
	str = 0;
	if (form_info->null > 0)
		ft_putchar_fd(0, 1);
}

void		parse(t_format *form_info, const char *form, int *ret)
{
	while (*form)
	{
		if (*form != '%')
		{
			ft_putchar_fd(*form++, 1);
			(*ret)++;
		}
		else
		{
			form++;
			init_format_list(form_info);
			while (read_flag(&form, form_info) ||
					read_width(&form, form_info) || read_dot(&form, form_info))
				;
			if (!(form_info->type = *(form++)))
				break ;
			str_putchar(form_info, ret);
		}
	}
}

int			ft_printf(const char *form, ...)
{
	t_format	*form_info;
	int			ret;

	if (!(form_info = (t_format*)malloc(sizeof(t_format))))
		return (0);
	ret = 0;
	va_start(form_info->ap, form);
	parse(form_info, form, &ret);
	va_end(form_info->ap);
	free(form_info);
	return (ret);
}
