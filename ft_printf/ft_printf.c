/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:23:46 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/27 17:23:23 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	init_format_list(void)
{
	t_format	ret;

	ret.minus = 0;
	ret.zero = 0;
	ret.dot = -1;
	ret.width = 0;
	ret.type = 0;
	return (ret);
}

int	ft_printf(const char *form, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, form);
	
}
