/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 21:00:57 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 18:27:09 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*set_player(int *location, char dir)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (0);
	player->pos[0] = (double)*location + 0.5;
	player->pos[1] = (double)*(location + 1) + 0.5;
	player->dir[0] = -1;
	player->dir[1] = 0;
	player->plane[0] = 0;
	player->plane[1] = 0.66;
	player->i = -1;
	while (++player->i < 6)
		player->key[player->i] = 0;
	player->seta = 0;
	if (dir == 'W')
		player->seta = 90;
	else if (dir == 'S')
		player->seta = 180;
	else if (dir == 'E')
		player->seta = -90;
	eyesight_lr(player, player->seta * 3.14 / 180);
	return (player);
}

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
	double	*pos;
	double	*dir;

	pos = player->pos;
	dir = player->dir;
	if (worldmap[(int)(pos[0] + dir[0] * flag)][(int)pos[1]] != ' ')
		pos[0] += dir[0] * flag;
	if (worldmap[(int)(pos[0])][(int)(pos[1] + dir[1] * flag)] != ' ')
		pos[1] += dir[1] * flag;
	return (1);
}

char		move_ad(t_player *player, char **worldmap, double flag, double pi)
{
	double	tmp_x;
	double	tmp_y;
	double	seta;
	double	*pos;
	double	*dir;

	pos = player->pos;
	dir = player->dir;
	seta = pi * 90;
	tmp_y = dir[0] * cos(seta) - dir[1] * sin(seta);
	tmp_x = dir[0] * sin(seta) + dir[1] * cos(seta);
	if (worldmap[(int)(pos[0] + tmp_y * flag)][(int)pos[1]] != ' ')
		pos[0] += tmp_y * flag;
	if (worldmap[(int)pos[0]][(int)(pos[1] + tmp_x * flag)] != ' ')
		pos[1] += tmp_x * flag;
	return (1);
}
