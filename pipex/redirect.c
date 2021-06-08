/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:32:14 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/08 18:19:28 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_in_child(char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		show_error("open file1 error");
	dup2(fd, 0);
	close(fd);
}

void	redirect_in_parent(char *file)
{
	int	fd;

	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
		show_error("open file2 error");
	dup2(fd, 1);
	close(fd);
}
