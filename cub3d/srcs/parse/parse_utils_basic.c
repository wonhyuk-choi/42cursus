/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:02 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:53:03 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_atoi(char **line, int *target)
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
	while (**line == ' ')
		(*line)++;
	if (**line == ',')
	{
		(*line)++;
		check = 1;
	}
	while (**line == ' ')
		(*line)++;
	return (check);
}

int		check_length(char *line)
{
	int	length;

	length = 0;
	while (*line++)
		length++;
	return (length);
}

int		new_array(char **target, char **line)
{
	int	tmp;

	*target = malloc(check_length(*line) + 1);
	if (!*target)
		return (0);
	tmp = 0;
	while (**line && **line != ' ')
	{
		*(*target + tmp++) = **line;
		(*line)++;
	}
	*(*target + tmp) = 0;
	return (1);
}

char	find_chr(const char *str, char target)
{
	while (*str)
	{
		if (*str == target)
			return (target);
		str++;
	}
	return (0);
}

char	*new_chr_array(char chr, int size)
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
