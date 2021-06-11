/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:08 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 16:42:54 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

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
	(*data)->texture_path = malloc(sizeof(char *) * 6);
	(*data)->worldmap = malloc(sizeof(char *) * 21);
	if (!(*data)->texture_path || !(*data)->worldmap)
		return (0);
	i = 0;
	while (i < 21)
		(*data)->worldmap[i++] = 0;
	i = 0;
	while (i < 6)
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
	//identifier(map 데이터를 제외한 파일의 모든 데이터) 별로 서로 다른 flag 값을 결정하여 반환한다.
	//이 flag 값은 이후 identifier를 구분하는 용도로 사용된다.
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
	else if (*line == 'D' && *(line + 1) == ' ')
		return (4);
	else if (*line == 'F' && *(line + 1) == ' ')
		return (5);
	else if (*line == 'C' && *(line + 1) == ' ')
		return (6);
	return (7);
}

static char	*set_data(t_parse *data, char *line, unsigned char *check)
{
	int	flag;
	//set_data 함수는 file에 있는 벽에 사용될 texture의 이미지 경로, 천장과 바닥의 색을 결정하는 값, 맵데이터를 저장한다.
	flag = check_flag(line);
	if (*check != 0xff)
	{
		//check의 값이 0xff란 말은 모든 identifier의 값을 받았다는 뜻으로 map 데이터 파싱 단계로 넘어감을 의미한다.
		//기존 check의 값은 0xc0 = 1100 0000으로 0의 개수는 identifier의 개수와 동일하다. 즉, 각 자리를 identifier가
		//들어왔는지 체크하는 flag 자리가 된다.
		if (!*line)
		{
			free(line);
			return (0);
		}
		if (flag == 7)
			return ("invalid identifier");
		//아래 연산은 check_flag 함수를 통해 받아온 flag의 수만큼 check의 값을 비트연산해주는 과정이다.
		//만약 flag가 3으로 'EA'값을 받은 경우 check값의 3번째 위치인 a위치를 검사해주어야 한다. (1100 a000)
		//따라서 3만큼 비트연산을 시행한 후 해당 위치가 1인지 비교해준다.
		//만약 해당 위치가 0인 경우 pow(2, flag)연산한 값을 check에 더해줌으로써 해당 위치를 1로 바꿀수 있다.(0000 1000 = 8) 8 = 2^3 = pow(2, 3);
		if ((*check >> flag & 1) == 1)
			return ("reduplication identifier");
		*check += (unsigned int)pow(2, flag);
		return (set_identifier(data, line, flag));
	}
	if (!*line && !*data->worldmap)
	{
		//해당 조건문은 identifirer가 전부 들어온 후 map 데이터를 저장하기 전 나오는 빈줄들을 제거하기 위해 사용된 함수이다.
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
	//0xc0 = 1100 0000을 의미한다. 이 값은 이후 identifier를 검사하는 경우 중복체크와 map 파싱과정으로 넘어가는 경우에 사용된다.
	check = 0x80;
	while (1)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			return ("get_next_line failed");
		//아래의 경우 gnl의 파일 읽기가 전부 끝난 경우를 의미한다. 이 경우 반복문을 벗어나 gnl로부터 읽어온 마지막 line('\0')을 바로 초기화한다.
		if (!result && !*line)
			break ;
		error = set_data(*data, line, &check);
		if (error)
			return (error);
	}
	free(line);
	//여기까지 identifier와 간단한 map 데이터 저장이 끝나게 되었다. resize_map 함수를 이용해 map의 크기를 일정하게 바꾼후 padding을 넣어주는 과정으로
	//넘어가게 된다.
	return (resize_map(*data));
}
