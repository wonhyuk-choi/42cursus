/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:52 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:52:52 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	x_icon(t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	exit(0);
	return (0);
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
	return (0);
}

int	active_apply(t_cub3d *cub3d)
{
	char	flag;

	flag = 0;
	if (cub3d->player->key[0] == 1)
		flag = move_ad(cub3d->player, cub3d->data->worldmap, 0.13);
	else if (cub3d->player->key[2] == 1)
		flag = move_ad(cub3d->player, cub3d->data->worldmap, -0.13);
	if (cub3d->player->key[1] == 1)
		flag = move_ws(cub3d->player, cub3d->data->worldmap, -0.13);
	else if (cub3d->player->key[3] == 1)
		flag = move_ws(cub3d->player, cub3d->data->worldmap, 0.13);
	if (cub3d->player->key[4] == 1)
		flag = eyesight_lr(cub3d->player, PIT * 1);
	else if (cub3d->player->key[5] == 1)
		flag = eyesight_lr(cub3d->player, PIT * -1);
	if (flag)
		ray_casting(cub3d, cub3d->player, cub3d->data);
	return (1);
}
