/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:39:22 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/22 15:52:49 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_press(int key, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (key == 4 || key == 5)
		fractol(data, key, -1, -1);
	return (0);
}

int	mouse_pos(int x, int y, t_data *data)
{
	if (data->fractol == 'J' && 0 <= x && x < data->w && 0 <= y && y < data->h)
	{
		data->mr = 5 * (x - data->w * 0.5) / (double)data->w;
		data->mi = 5 * (y - data->h * 0.5) / (double)data->h;
		fractol(data, 0, -1, -1);
	}
	return (0);
}

int	x_icon(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == 53)
	{
		free_data(data);
		exit(0);
	}
	if (key == 8)
	{
		data->color_range = (data->color_range + 1) % 3;
		fractol(data, 0, -1, -1);
	}
	return (0);
}
