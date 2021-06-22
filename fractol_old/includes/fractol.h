/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:42:08 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/18 00:32:50 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

typedef struct	s_image
{
	void	*mlx;
	void	*win;
	void	*ptr;
	void	*adr;
	int		win_w;
	int		win_h;
	int		bpp;
	int		len;
	int		endian;
}				t_image;

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_fractol
{
	t_image		*image;
	t_complex	re;
	t_complex	im;
	int			fractol_num;
	double		h;
	double		w;
	double		img_w;
	double		img_h;
	int			zoom;
	int			iter;
	int			iter_max;
	int			color;
}				t_fractol;

int		ft_strcmp(char const *s1, char const *s2);
int		check_fractol(char *name, t_fractol *fractol);

int		color_set(int iter, int iter_max);
void	img_pixel_put(t_image *image, int x, int y, int color);
void	fractol_resize(t_fractol *fractol);
void	fractol_select(t_fractol *fractol);
void	draw(t_fractol *fractol);

int		mandelbrot(t_fractol *fractol);
int		julia(t_fractol *fractol);
int		burningship(t_fractol *fractol);

int		julia_move(int x, int y, t_fractol *fractol);
int		mouse_move(int key, int x, int y, t_fractol *fractol);
int		key_hook(int key, t_fractol *fractol);
int		x_icon(t_fractol *fractol);

#endif
