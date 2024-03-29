/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:32:06 by wonchoi           #+#    #+#             */
/*   Updated: 2021/02/07 20:40:21 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_format
{
	int			minus;
	int			zero;
	int			dot;
	int			width;
	int			null;
	char		type;
	va_list		ap;
}				t_format;

char			*check_form(t_format *form_info);
void			parse(t_format *form_info, const char *form, int *ret);
int				ft_printf(const char *form, ...);

int				read_flag(const char **form, t_format *form_info);
int				read_width(const char **form, t_format *form_info);
int				read_dot(const char **form, t_format *form_info);

void			check_form_c(char **form_str, char c, t_format *form_info);
void			check_form_s(char **form_str, t_format *form_info);
void			check_form_di(char **form_str, t_format *form_info);
void			check_form_p(char **form_str, t_format *form_info);
void			check_form_u(char **form_str, t_format *form_info);
void			check_form_x(char **form_str, t_format *form_info);
void			check_form_lx(char **form_str, t_format *form_info);

char			*dtoa(unsigned long long num, char base[10]);
char			*utoa(unsigned long long num, char base[16]);
char			*save_str(char c, int count);
char			*join_str(char *lest, char *right);
void			join_zero(char **form_str, int num);

#endif
