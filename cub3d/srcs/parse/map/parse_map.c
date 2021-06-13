/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:23 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 17:15:40 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

	new_col = malloc(sizeof(char *) * (max + 1 + padding));
	if (!new_col)
		return (0);
	i = 0;
	if (padding)
		if (!(set_padding(new_col, max + padding, width + padding)))
			return (0);
	while (*(*target + i))
	{
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
