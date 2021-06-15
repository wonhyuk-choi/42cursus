/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:36:45 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/15 14:59:41 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
