/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:42:24 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/18 00:34:38 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_set(int iter, int iter_max)
{
	int		rgb[3];
	float	tmp;

	tmp = (double)iter / (double)iter_max;
	rgb[0] = (int)(9 * (1 - tmp) * pow(tmp, 3) * 255);
	rgb[1] = (int)(15 * pow((1 - tmp), 2) * pow(tmp, 2) * 255);
	rgb[2] = (int)(8 * pow((1 - tmp), 3) * tmp * 255);
	return (rgb[0] | (rgb[1] << 8) | (rgb[2] << 16));
}

void	img_pixel_put(t_image *image, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		*(int *)(image->adr + ((x + (y * WIN_WIDTH)) * image->bpp)) = color;
}

void	fractol_resize(t_fractol *fractol)
{
	fractol->h = (double)(fractol->h - fractol->img_h) / fractol->zoom;
	fractol->w = (double)(fractol->w - fractol->img_w) / fractol->zoom;
}

void	fractol_select(t_fractol *fractol)
{
	if (fractol->fractol_num == 1)
		fractol->iter = mandelbrot(fractol);
	if (fractol->fractol_num == 2)
		fractol->iter = julia(fractol);
	if (fractol->fractol_num == 3)
		fractol->iter = burningship(fractol);
}

void	draw(t_fractol *fractol)
{
	int		w;
	int		h;
	t_image	*image;

	h = 0;
	while (h < WIN_WIDTH)
	{
		w = 0;
		while (w < WIN_HEIGHT)
		{
			fractol->w = w;
			fractol->h = h;
			fractol_resize(fractol);
			fractol_select(fractol);
			fractol->color = color_set(fractol->iter, fractol->iter_max);
			img_pixel_put(fractol->image, h, w, fractol->color);
			w++;
		}
		h++;
	}
}
