/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:23:36 by wonchoi           #+#    #+#             */
/*   Updated: 2021/07/14 22:05:11 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_print(char *str, int err)
{
	write(1, "Error: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(err);
}
