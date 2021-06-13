/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:52 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/12 02:14:04 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	mouse_pos(int x, int y, t_cub3d *cub3d)
{
	if (!cub3d->player->mouse_switch)
		return (0);
	y = 0;
	cub3d->player->i = x;
	cub3d->player->key[6] = 1;
	return (0);
}

int	x_icon(t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	exit(0);
}

int	key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == 53)
	{
		free_cub3d(cub3d);
		exit(0);
	}
	if (0 <= keycode && keycode <= 2)
		cub3d->player->key[keycode] = 1;
	if (keycode == 13)
		cub3d->player->key[3] = 1;
	if (keycode == 123 || keycode == 124)
		cub3d->player->key[keycode - 119] = 1;
	if (keycode == 45)
	{
		cub3d->player->mouse_switch = 1 - cub3d->player->mouse_switch;
		if (!cub3d->player->mouse_switch)
			cub3d->player->key[6] = 0;
	}
	return (0);
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode >= 0 && keycode <= 2)
		cub3d->player->key[keycode] = 0;
	if (keycode == 13)
		cub3d->player->key[3] = 0;
	if (keycode == 123 || keycode == 124)
		cub3d->player->key[keycode - 119] = 0;
	if (keycode == 49)
		cub3d->player->key[7] = 1;
	return (0);
}

int	active_apply(t_cub3d *cub3d)
{
	t_parse	*data;
	char	flag;

	data = cub3d->data;
	flag = 0;
	if (cub3d->player->key[0] == 1)
		flag = move_ad(cub3d->player, data->worldmap, 0.1, data->pi);
	else if (cub3d->player->key[2] == 1)
		flag = move_ad(cub3d->player, data->worldmap, -0.1, data->pi);
	if (cub3d->player->key[1] == 1)
		flag = move_ws(cub3d->player, data->worldmap, -0.1);
	else if (cub3d->player->key[3] == 1)
		flag = move_ws(cub3d->player, data->worldmap, 0.1);
	if (cub3d->player->key[4] == 1)
		flag = eyesight_lr(cub3d->player, data->pi * 1.5);
	else if (cub3d->player->key[5] == 1)
		flag = eyesight_lr(cub3d->player, data->pi * -1.5);
	if (cub3d->player->key[6] == 1)
		flag = rotate_mouse(cub3d->player, cub3d->data->pi);
	if (cub3d->player->key[7] == 1)
		flag = change_door_state(cub3d->player, data->worldmap);
	if (flag)
		ray_casting(cub3d, cub3d->player, data);
	return (1);
}
