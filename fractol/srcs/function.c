/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:21:02 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/22 15:47:02 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data *data, int max, int flag, char *dst)
{
	unsigned int	color;

	if (data->color_range == 1)
	{
		if (flag == max)
			color = 0x00000000;
		else
			color = 0x00000ff0 + 0x000000f0 * (int)(flag * 0.5);
	}
	else if (data->color_range == 2)
	{
		if (flag == max)
			color = 0x00000000;
		else
			color = 0x000ff000 + 0x0000f000 * (int)(flag * 0.5);
	}
	else
	{
		if (flag == max)
			color = 0x00000000;
		else
			color = 0x0ff00000 + 0x00f00000 * (int)(flag * 0.5);
	}
	*(unsigned int *)dst = color;
}

int		name_check(t_data *data)
{
	int	name;

	name = 1;
	if (data->fractol == 'M')
		name = 2;
	else if (data->fractol == 'B')
		name = 3;
	return (name);
}

int		name_to_flag_check(t_data *data, double r, int name)
{
	int	flag;

	if (name == 1)
		flag = draw_julia(r, data->i, data);
	else if (name == 2)
		flag = draw_mandelbrot(r, data->i, data);
	else if (name == 3)
		flag = draw_burningship(r, data->i, data);
	return (flag);
}

void	fractol(t_data *data, int key, int x, int y)
{
	double	r;
	int		name;
	int		flag;

	if (!(set_value(data, key)))
		exit (1);
	name = name_check(data);
	while (++y < data->h)
	{
		x = -1;
		r = data->r;
		while (++x < data->w)
		{
			flag = name_to_flag_check(data, r, name);
			draw(data, data->max, flag, data->adr + y * data->len \
			 + x * data->bpp);
			r += data->ratio_x;
		}
		data->i += data->ratio_y;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	mlx_destroy_image(data->mlx, data->image);
	data->image = 0;
}
