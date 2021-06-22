/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:23:25 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/18 00:06:54 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_move(int x, int y, t_fractol *fractol)
{
	fractol->im.x = 4 * ((double)x / fractol->image->win_w - 0.5);
	fractol->im.y = 4 * ((double)(fractol->image->win_h - y)
			/ fractol->image->win_h - 0.5);
	draw(fractol);
	mlx_put_image_to_window(fractol->image->mlx, fractol->image->win, fractol->image->ptr, 0, 0);
	return (0);
}

int	mouse_move(int key, int x, int y, t_fractol *fractol)
{
	if (key == 4)
		fractol->zoom *= 0.9;
	if (key == 5)
		fractol->zoom *= 1.1;
	fractol->img_h = y;
	fractol->img_w = x;
	draw(fractol);
	mlx_put_image_to_window(fractol->image->mlx, fractol->image->win, fractol->image->ptr, 0, 0);
	return (0);
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == 53)
	{
		exit(0);
	}
	draw(fractol);
	mlx_put_image_to_window(fractol->image->mlx, fractol->image->win, fractol->image->ptr, 0, 0);
	return (0);
}

int	x_icon(t_fractol *fractol)
{
	exit(0);
	return (0);
}