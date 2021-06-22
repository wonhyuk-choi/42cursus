/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:00:53 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/18 00:00:55 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *fractol)
{
	int			iter;
	t_complex	c;

	iter = 0;
	fractol->re.x = 0;
	fractol->re.y = 0;
	while (iter < fractol->iter_max)
	{
		c = fractol->re;
		fractol->re.x = pow(c.x, 2) - pow(c.y, 2) + fractol->h;
		fractol->re.y = 2 * c.x * c.y + fractol->w;
		iter++;
		if ((c.x * c.x + c.y * c.y) > 4)
			break ;
	}
	return (iter);
}

int	julia(t_fractol *fractol)
{
	int			iter;
	t_complex	c;

	iter = 0;
	fractol->re.x = 0;
	fractol->re.y = 0;
	while (iter < fractol->iter_max)
	{
		c = fractol->re;
		fractol->re.x = c.x * c.x - c.y * c.y + fractol->h;
		fractol->re.y = 2 * c.x * c.y + fractol->w;
		iter++;
		if ((c.x * c.x + c.y * c.y) > 4)
			break ;
	}
	return (iter);
}

int	burningship(t_fractol *fractol)
{
	int			iter;
	t_complex	c;

	iter = 0;
	fractol->re.x = 0;
	fractol->re.y = 0;
	while (iter < fractol->iter_max)
	{
		c = fractol->re;
		fractol->re.x = c.x * c.x - c.y * c.y + fractol->h;
		fractol->re.y = 2 * c.x * c.y + fractol->w;
		iter++;
		if ((c.x * c.x + c.y * c.y) > 4)
			break ;
	}
	return (iter);
}