/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:50:36 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/16 18:59:53 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_is_enter(char *backup)
{
	int	count;

	count = 0;
	while (backup[count] != '\0')
	{
		if (backup[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

int	ft_split_line(char **backup, char **line, int check)
{
	size_t	len;
	char	*tmp;

	(*backup)[check] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + check + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup(*backup + check + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int	ft_end(char **backup, char **line)
{
	int	index;

	if (*backup && (index = ft_is_enter(*backup)) >= 0)
		return (ft_split_line(backup, line, index));
	else if (*backup)	
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*backup[256];
	int			fdnum;
	int			check;

	buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || !buff || BUFFER_SIZE < 1)
		return (-1);
	while ((fdnum = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[fdnum] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		if ((check = ft_is_enter(backup[fd])) >= 0)
		{
			free(buff);
			return (ft_split_line(&backup[fd], line, check));
		}
	}
	free(buff);
	if (fdnum < 0)
		return (-1);
	return (ft_end(&backup[fd], line));
}
