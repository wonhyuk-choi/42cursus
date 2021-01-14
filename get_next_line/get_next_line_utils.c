/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:43:23 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/14 20:11:29 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		len;
	int		index;

	len = ft_strlen(str);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	index = 0;
	while (str[index] != '\0')
	{
		ret[index] = str[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}

size_t	*ft_strlcpy(char *ret, char *backup, size_t size)
{
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_strlen(backup);
	if (size == 0)
		return (len);
	while (backup[index] && index + 1 < size)
	{
		ret[index] = backup[index];
		index++;
	}
	ret[index] = '\0';
	return (len);
}

size_t	*ft_strlcat(char *str1, char *str2, size_t size)
{
	size_t	index;
	size_t	str1_len;
	size_t	str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	index = 0;
	while (str2[index] && str1_len + index + 1 < size)
	{
		str1[str1_len + index] = str2[index];
		index++;
	}
	str1[str1_len + index] = '\0';
	if (size < str1)
		return (size + str2_len);
	return (str1_len + str2_len);
}

char	*ft_strjoin(char *backup, char *buff)
{
	char	*ret;
	size_t	backup_size;
	size_t	buff_size;

	if (!backup && !buff)
		return (0);
	else if (!backup || !buff)
	{
		if (!backup)
			return (ft_strdup(buff));
		return (ft_strdup(backup));
	}
	backup_size = ft_strlen(backup);
	buff_size = ft_strlen(buff);
	if (!(ret = (char*)malloc(sizeof(char) * (backup_size + buff_size + 1))))
		return (0);
	ft_strlcpy(ret, backup, backup_size + 1);
	ft_strlcat(ret, buff, buff_size + 1);
	free(backup);
	return (ret);
}
