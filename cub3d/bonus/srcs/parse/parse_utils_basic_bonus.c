/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_basic_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:02 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 17:20:22 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int			parse_atoi(char **line, int *target)
{
	int	i;
	int	check;

	i = 3;
	check = 0;
	while (**line == '0')
		(*line)++;
	while (**line >= '0' && **line <= '9' && i--)
	{
		*target = (*target * 10) + **line - 48;
		(*line)++;
	}
	while (**line == ' ' || **line == ',')
	{
		if (**line == ',')
			check++;
		(*line)++;
	}
	return (check);
}

static int	check_length(char *line)
{
	int	leng;
	int	space_leng;

	leng = 0;
	space_leng = 0;
	while (*line)
	{
		line++;
		leng++;
	}
	line--;
	while (*line == ' ')
	{
		space_leng++;
		line--;
	}
	return (leng - space_leng);
}

int			make_path_str(char **target, char **line)
{
	int	tmp;
	int	path_leng;

	path_leng = check_length(*line);
	*target = malloc(path_leng + 1);
	if (!*target)
		return (0);
	tmp = 0;
	while (tmp < path_leng)
	{
		*(*target + tmp++) = **line;
		(*line)++;
	}
	*(*target + tmp) = 0;
	while (**line)
		(*line)++;
	return (1);
}

char		find_chr(const char *str, char target)
{
	while (*str)
	{
		if (*str == target)
			return (target);
		str++;
	}
	return (0);
}

char		*new_chr_array(char chr, int size)
{
	char	*cur;
	int		i;

	cur = malloc(size + 1);
	if (!cur)
		return (0);
	i = 0;
	while (i < size)
		*(cur + i++) = chr;
	*(cur + i) = 0;
	return (cur);
}
