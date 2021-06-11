/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:28 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:53:29 by taewakim         ###   ########.fr       */
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
	//xpm 확장자또한 처리하는지 확인, 마지막이 png로 끝나는지 확인
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
		//parse_atoi 함수는 반환값으로 ','의 개수를 반환하다. ','의 개수로 만들어진 color가 정상적인지 판단한다.
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
	//위쪽의 반복문들은 앞서 check_flag에서 읽었던 부분들을 넘겨주기 위함이다. ex) 'EA '
	//아래 조건문은 벽에 사용될 texture의 경로를 처리하는 함수이다.
	if (flag >= 0 && flag <= 4)
		error = set_wall_texture_path(data, line, flag);
	else if (flag == 5 || flag == 6)
		error = read_color(data, line, flag);
	//위 조건문은 천장과 바닥에 사용될 색상을 읽어 저장하는 함수이다.
	free(save);
	return (error);
}
