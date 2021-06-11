/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:28 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 17:19:56 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static char	check_png(char *line)
{
	int	i;

	line--;
	while (*line == ' ')
		line--;
	i = 0;
	while (i++ < 4)
	{
		if (65 <= *line && *line <= 90)
			*line -= 32;
		line--;
	}
	line++;
	if (*line == '.' && *(line + 1) == 'p' && *(line + 2) == 'n'
	&& *(line + 3) == 'g')
		return (1);
	return (0);
}

static char	*set_wall_texture_path(t_parse *data, char *line, int flag)
{
	int	fd;

	if (!make_path_str(data->texture_path + flag, &line))
		return ("set_wall_texture_path malloc failed");
	if (*line)
		return ("invalid wall_path");
	if (!check_png(line))
		return ("invalid wall_path");
	fd = open(*(data->texture_path + flag), O_RDONLY);
	if (fd == -1)
		return ("invalid wall_path");
	else
		close(fd);
	return (0);
}

static char	*read_color(t_parse *data, char *line, int flag)
{
	int	i;
	int	tmp;
	int	tmp_color;

	i = 0;
	tmp = 0;
	while (i < 3)
	{
		tmp_color = 0;
		tmp += parse_atoi(&line, &tmp_color);
		if (tmp_color > 255)
			return ("invalid color");
		data->color[flag - 5] += tmp_color;
		if (i != 2)
			data->color[flag - 5] = data->color[flag - 5] << 8;
		i++;
	}
	if (tmp != 2 || *line)
		return ("invalid color");
	return (0);
}

char		*set_identifier(t_parse *data, char *line, int flag)
{
	char	*save;
	char	*error;

	save = line;
	error = 0;
	while (*line == ' ')
		line++;
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	if (flag >= 0 && flag <= 4)
		error = set_wall_texture_path(data, line, flag);
	else if (flag == 5 || flag == 6)
		error = read_color(data, line, flag);
	free(save);
	return (error);
}
