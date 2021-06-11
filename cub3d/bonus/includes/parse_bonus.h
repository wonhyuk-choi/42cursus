/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:54:42 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:30:01 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include <fcntl.h>
# include "get_next_line_bonus.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_parse
{
	int			resol_x;
	int			resol_y;
	int			col_size;
	int			row_max;
	int			location[2];
	int			color[2];
	int			col_max;
	char		direction;
	char		**worldmap;
	char		**texture_path; // texture[0] = NO, [1] = SO, [2] = WE, [3] = EA, [4] = S
	double		pi;
}				t_parse;

char			*parse(t_parse **data, char *map_path);
void			free_data(t_parse *data);

char			*set_identifier(t_parse *data, char *line, int flag);

char			*set_map(t_parse *data, char *line);
char			*resize_map(t_parse *data);
char			*check_map_validation(t_parse *data, int max);

int				parse_atoi(char **line, int *target);
int				make_path_str(char **target, char **line);
char			find_chr(const char *str, char target);
char			*new_chr_array(char chr, int size);

void			data_print(t_parse *data);

#endif
