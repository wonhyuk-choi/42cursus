/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:50:36 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/09 21:54:29 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>         // printf()
#include <string.h>        // strlen()
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()

int	get_next_line(int fd, char **line)
{
	char	*buf;
	char	*bakcup[OPEN_MAX];

}

