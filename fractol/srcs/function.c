/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:21:02 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/15 21:04:16 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(int max, int flag, char *dst)
{
	unsigned int	color;

	if (flag == max)
		color = 0x00000000;
	else
		color = 0x00000ff0 + 0x000000f0 * (int)(flag * 0.5);
	*(unsigned int *)dst = color;
}

void	fractol(t_data *data, int key, int x, int y)
{
	double	r;
	int 	name;
	int		flag;

	if (!(set_value(data, key)))
		exit (1);
	name = 1;
	if (data->fractol == 'M')
		name = 2;
	else if (data->fractol == 'B')
		name = 3;
	while (++y < data->h)
	{
		x = -1;
		r = data->r;
		while (++x < data->w)
		{
			if (name == 1)
				flag = draw_julia(r, data->i, data);
			else if (name == 2)
				flag = draw_mandelbrot(r, data->i, data);
			else if (name == 3)
				flag = draw_burningship(r, data->i, data);
			draw(data->max, flag, data->adr + y * data->len + x * data->bpp);
			r += data->ratio_x;
		}
		data->i += data->ratio_y;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	mlx_destroy_image(data->mlx, data->image);
	data->image = 0;
}