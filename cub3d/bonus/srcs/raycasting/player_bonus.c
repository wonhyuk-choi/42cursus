/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 21:00:57 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 21:52:51 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_bonus.h"

t_player	*set_player(int *location, char dir, int x)
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
	player->location_x = x;
	player->mouse_switch = 0;
	player->i = -1;
	while (++player->i < 8)
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
