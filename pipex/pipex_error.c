/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:23:36 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/07 17:37:21 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_wrtie(char *str)
{
	ft_putstr_fd(str, 1);
	write(2, "\n", 1);
	return (1);
}

int	show_error(char *str)
{
	perror(str);
	return (1);
}
