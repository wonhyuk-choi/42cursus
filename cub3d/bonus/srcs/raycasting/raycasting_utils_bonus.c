/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:41 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 17:26:33 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void			set_wall_draw_point(t_dda *dda, t_parse *data)
{
	int	height;
	int	screen_height;

	height = (int)(data->resol_y / dda->walldist);
	screen_height = data->resol_y;
	*dda->point = (-height + screen_height) / 2;
	*(dda->point + 1) = (height + screen_height) / 2;
}

char			*select_texture(t_texture **texture, t_dda *dda, char door_flag)
{
	int	tmp;

	if (door_flag == '2')
		dda->cur = texture[4];
	else
	{
		dda->cur = texture[3];
		if (!(dda->side) && dda->ray[0] < 0)
			dda->cur = texture[0];
		else if (!dda->side && dda->ray[0] > 0)
			dda->cur = texture[1];
		else if (dda->side == 1 && dda->ray[1] < 0)
			dda->cur = texture[2];
	}
	dda->cur->ratio = (double)(dda->cur->size[1]);
	dda->cur->ratio /= (double)(dda->point[1] - dda->point[0] + 1);
	tmp = (int)(dda->wall_x * (dda->cur->size[0])) * dda->cur->bpp;
	return (dda->cur->adr + tmp);
}

void			set_dda_value(t_dda *dda, t_player *player, int resol_x
, int x)
{
	int		i;
	double	tmp;

	i = 0;
	tmp = 2 * x / (double)resol_x - 1;
	while (i < 2)
	{
		dda->map[i] = (int)(player->pos[i]);
		dda->point[i] = 0;
		dda->ray[i] = player->dir[i] + player->plane[i] * tmp;
		dda->deltadist[i] = fabs(1 / dda->ray[i]);
		dda->step[i] = -1;
		dda->sidedist[i] = player->pos[i] - dda->map[i];
		if (dda->ray[i] >= 0)
		{
			dda->step[i] = 1;
			dda->sidedist[i] = (-1 * dda->sidedist[i]) + 1.0;
		}
		dda->sidedist[i] *= dda->deltadist[i];
		i++;
	}
	dda->side = 0;
}

char			hit_wall(t_dda *dda, char **map, double *pos)
{
	int	s;

	s = 0;
	while (map[dda->map[0]][dda->map[1]] != '1'
	&& map[dda->map[0]][dda->map[1]] != '2')
	{
		s = 0;
		if (dda->sidedist[1] < dda->sidedist[0])
			s = 1;
		dda->sidedist[s] += dda->deltadist[s];
		dda->map[s] += dda->step[s];
	}
	dda->walldist = dda->map[s] - pos[s] + (1 - dda->step[s]) / 2;
	dda->walldist /= dda->ray[s];
	dda->wall_x = pos[1 - s] + dda->walldist * dda->ray[1 - s];
	dda->wall_x -= floor(dda->wall_x);
	dda->side = s;
	return (map[dda->map[0]][dda->map[1]]);
}
