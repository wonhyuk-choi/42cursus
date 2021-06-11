/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:53:06 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 22:07:02 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_bonus.h"

char		eyesight_lr(t_player *player, double seta)
{
	double	tmp;
	double	*plane;
	double	*dir;

	dir = player->dir;
	plane = player->plane;
	tmp = dir[0];
	dir[0] = dir[0] * cos(seta) - dir[1] * sin(seta);
	dir[1] = tmp * sin(seta) + dir[1] * cos(seta);
	tmp = plane[0];
	plane[0] = plane[0] * cos(seta) - plane[1] * sin(seta);
	plane[1] = tmp * sin(seta) + plane[1] * cos(seta);
	return (1);
}

char		move_ws(t_player *player, char **worldmap, double flag)
{
	char	object;
	double	*pos;
	double	*dir;

	pos = player->pos;
	dir = player->dir;
	object = worldmap[(int)(pos[0] + dir[0] * flag)][(int)pos[1]];
	if (object != '1' && object != '2')
		pos[0] += dir[0] * flag;
	object = worldmap[(int)(pos[0])][(int)(pos[1] + dir[1] * flag)];
	if (object != '1' && object != '2')
		pos[1] += dir[1] * flag;
	return (1);
}

char		move_ad(t_player *player, char **worldmap, double flag, double pi)
{
	char	object;
	double	tmp[2];
	double	seta;
	double	*pos;
	double	*dir;

	pos = player->pos;
	dir = player->dir;
	seta = pi * 90;
	tmp[1] = dir[0] * cos(seta) - dir[1] * sin(seta);
	tmp[0] = dir[0] * sin(seta) + dir[1] * cos(seta);
	object = worldmap[(int)(pos[0] + tmp[1] * flag)][(int)pos[1]];
	if (object != '1' && object != '2')
		pos[0] += tmp[1] * flag;
	object = worldmap[(int)pos[0]][(int)(pos[1] + tmp[0] * flag)];
	if (object != '1' && object != '2')
		pos[1] += tmp[0] * flag;
	return (1);
}

char		change_door_state(t_player *player, char **worldmap)
{
	double	*pos;
	double	*dir;

	pos = player->pos;
	dir = player->dir;
	if (worldmap[(int)(pos[0] + 1)][(int)pos[1]] == '2')
		worldmap[(int)(pos[0] + 1)][(int)pos[1]] = '3';
	else if (worldmap[(int)(pos[0] + 1)][(int)pos[1]] == '3')
		worldmap[(int)(pos[0] + 1)][(int)pos[1]] = '2';
	if (worldmap[(int)(pos[0] - 1)][(int)pos[1]] == '2')
		worldmap[(int)(pos[0] - 1)][(int)pos[1]] = '3';
	else if (worldmap[(int)(pos[0] - 1)][(int)pos[1]] == '3')
		worldmap[(int)(pos[0] - 1)][(int)pos[1]] = '2';
	if (worldmap[(int)pos[0]][(int)(pos[1] - 1)] == '2')
		worldmap[(int)pos[0]][(int)(pos[1] - 1)] = '3';
	else if (worldmap[(int)pos[0]][(int)(pos[1] - 1)] == '3')
		worldmap[(int)pos[0]][(int)(pos[1] - 1)] = '2';
	if (worldmap[(int)pos[0]][(int)(pos[1] + 1)] == '2')
		worldmap[(int)pos[0]][(int)(pos[1] + 1)] = '3';
	else if (worldmap[(int)pos[0]][(int)(pos[1] + 1)] == '3')
		worldmap[(int)pos[0]][(int)(pos[1] + 1)] = '2';
	player->key[7] = 0;
	return (1);
}

char		rotate_mouse(t_player *player, double pi)
{
	if (player->i < player->location_x - 100)
		eyesight_lr(player, pi * 1.5);
	else if (player->i > player->location_x + 100)
		eyesight_lr(player, pi * -1.5);
	else
		player->key[6] = 0;
	return (1);
}
