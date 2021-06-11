/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:23 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 14:55:55 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static int	set_padding(char **target, int max, int width)
{
	target[0] = new_chr_array(' ', width);
	if (!target[0])
	{
		free(target);
		return (0);
	}
	target[max - 1] = new_chr_array(' ', width);
	if (!target[max - 1])
	{
		free(target[0]);
		free(target);
		return (0);
	}
	target[max] = 0;
	return (1);
}

static int	resize_col(char ***target, int max, int padding, int width)
{
	char	**new_col;
	int		i;

	//padding은 기본적으로는 0이 들어오지만 map의 크기를 최종적으로 재조정하는 과정에는 2가 들어와
	//map의 처음과 마지막 열에 ' '로 구성된 문자열을 추가한다. 이 padding은 이후 벽충돌과 map 유효성 검사에서 사용된다.
	new_col = malloc(sizeof(char *) * (max + 1 + padding));
	if (!new_col)
		return (0);
	i = 0;
	if (padding)
		if (!(set_padding(new_col, max + padding, width + padding)))
			return (0);
	while (*(*target + i))
	{
		//아래 padding / 2의 값을 더해주는 이유는 padding이 추가되는 경우 데이터를 넣어주는 시작점을 padding이 존재하는
		//첫 라인이 아닌 그 다음 라인부터 진행하기 위함이다.
		*(new_col + i + (padding / 2)) = *(*target + i);
		i++;
	}
	while (i < max + 1 && !padding)
		*(new_col + i++) = 0;
	free(*target);
	*target = new_col;
	return (1);
}

static int	resize_row(char **worldmap, int max)
{
	//resize_row함수는 map을 최종적으로 조정할 때 사용되는 함수로 이전까지 비교하여 저장해두었던
	//data->row_max (map의 최대 너비)의 값을 이용해 map의 너비를 통일해주는 고정이다.
	char	*new_row;
	int		i;
	int		j;

	i = 0;
	while (worldmap[i])
	{
		new_row = malloc(max + 1);
		if (!new_row)
			return (0);
		new_row[0] = ' ';
		j = -1;
		while (worldmap[i][++j])
			new_row[j + 1] = worldmap[i][j];
		j++;
		while (j < max)
			new_row[j++] = ' ';
		new_row[j] = 0;
		free(worldmap[i]);
		worldmap[i] = new_row;
		i++;
	}
	return (1);
}

char		*set_map(t_parse *data, char *line)
{
	int	i;

	//아래 조건문은 미리 정해둔 맵의 줄수를 넘어갈 경우 사이즈를 재조정하기 위해 구현한 것이다.
	//맵의 데이터가 20(col_max)에 도달한 경우 col_max의 값을 늘려 크기 조정을 진행한다.
	if (data->col_size == data->col_max)
	{
		data->col_max += 10;
		if (!resize_col(&data->worldmap, data->col_max, 0, 0))
		{
			free(line);
			return ("resize_col failed");
		}
	}
	*(data->worldmap + data->col_size++) = line;
	i = 0;
	while (*(line + i))
		i++;
	//아래 조건문은 map의 row길이의 최대값을 구해 이후 map 크기를 최종적으로 조정할 때 사용한다.
	if (data->row_max < i)
		data->row_max = i;
	return (0);
}

char		*resize_map(t_parse *data)
{
	if (!resize_row(data->worldmap, data->row_max + 2))
		return ("resize_row failed");
	if (!resize_col(&data->worldmap, data->col_size, 2, data->row_max))
		return ("resize_col failed");
	return (check_map_validation(data, data->row_max + 2));
}
