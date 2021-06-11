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

#include "parse_bonus.h"

int		parse_atoi(char **line, int *target)
{
	int	i;
	int	check;

	i = 3;
	check = 0;
	//아래 반복문은 0~255를 읽는 과정을 3번으로 제한하였기 때문에 00000255 이런식으로 들어오는 경우 정상적인 처리를
	//하기 위해 추가한 코드이다.
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
	//아래 반복문의 경우 정상적인 파일 경로 뒤에 추가적으로 space가 들어오는 경우를 처리해주기 위해 추가하였다.
	while (*line == ' ')
	{
		space_leng++;
		line--;
	}
	return (leng - space_leng);
}

int		make_path_str(char **target, char **line)
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
