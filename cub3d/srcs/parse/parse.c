/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:08 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 17:27:04 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		free_data(t_parse *data)
{
	int	i;

	i = 0;
	if (data->worldmap)
	{
		while (data->worldmap[i])
			free(data->worldmap[i++]);
		free(data->worldmap);
		i = 0;
	}
	if (data->texture_path)
	{
		while (data->texture_path[i])
			free(data->texture_path[i++]);
		free(data->texture_path);
	}
}

static char	init_parse(t_parse **data)
{
	int		i;
	char	*start;

	*data = malloc(sizeof(t_parse));
	if (!*data)
		return (0);
	(*data)->texture_path = malloc(sizeof(char *) * 5);
	(*data)->worldmap = malloc(sizeof(char *) * 21);
	if (!(*data)->texture_path || !(*data)->worldmap)
		return (0);
	i = 0;
	while (i < 21)
		(*data)->worldmap[i++] = 0;
	i = 0;
	while (i < 5)
		(*data)->texture_path[i++] = 0;
	(*data)->direction = 0;
	i = 0;
	start = (char *)&(*data)->resol_x;
	while (i < 36)
		start[i++] = 0;
	(*data)->col_max = 20;
	(*data)->pi = 3.14 / 180;
	return (1);
}

static int	check_flag(char *line)
{
	while (*line == ' ')
		line++;
	if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (0);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (1);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		return (2);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		return (3);
	else if (*line == 'F' && *(line + 1) == ' ')
		return (4);
	else if (*line == 'C' && *(line + 1) == ' ')
		return (5);
	return (6);
}

static char	*set_data(t_parse *data, char *line, unsigned char *check)
{
	int	flag;

	flag = check_flag(line);
	if (*check != 0xff)
	{
		if (!*line)
		{
			free(line);
			return (0);
		}
		if (flag == 6)
			return ("invalid identifier");
		if ((*check >> flag & 1) == 1)
			return ("reduplication identifier");
		*check += (unsigned int)pow(2, flag);
		return (set_identifier(data, line, flag));
	}
	if (!*line && !*data->worldmap)
	{
		free(line);
		return (0);
	}
	return (set_map(data, line));
}

char		*parse(t_parse **data, char *map_path)
{
	int				fd;
	int				result;
	char			*line;
	char			*error;
	unsigned char	check;

	if (!init_parse(data))
		return ("init_parse failed");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return ("invalid map path");
	check = 0xc0;
	while (1)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			return ("get_next_line failed");
		if (!result && !*line)
			break ;
		error = set_data(*data, line, &check);
		if (error)
			return (error);
	}
	free(line);
	return (resize_map(*data));
}
