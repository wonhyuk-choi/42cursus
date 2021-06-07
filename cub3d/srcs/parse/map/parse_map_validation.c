/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:19 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:24:50 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	around_check(char **map, int col, int row)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
			if (map[col + i][row + j] == ' ')
				return (0);
	}
	return (1);
}

static char	*set_elem(t_parse *data, int col, int row)
{
	char	cur;

	cur = data->worldmap[col][row];
	if (cur == ' ' || cur == '1')
		return (0);
	else if (cur != '0')
	{
		if (data->direction)
			return ("player reduplication error");
		data->direction = cur;
		data->location[0] = row;
		data->location[1] = col;
		data->worldmap[col][row] = '0';
	}
	if (!around_check(data->worldmap, col, row))
		return ("invalid map");
	return (0);
}

char		*map_validation(t_parse *data, int max)
{
	int		col;
	int		row;
	char	*error;

	col = 0;
	while (++col < data->col_size + 1)
	{
		row = 0;
		while (++row < max - 1)
		{
			if (!find_chr(" 01WENS", data->worldmap[col][row]))
				return ("invalid map");
			error = set_elem(data, col, row);
			if (error)
				return (error);
		}
	}
	if (!data->direction)
		return ("player not exist");
	return (0);
}
