/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:42:08 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/22 16:14:15 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*adr;
	char	fractol;
	int		bpp;
	int		len;
	int		endian;
	int		w;
	int		h;
	int		max;
	int		color_range;
	double	zoom;
	double	ratio_x;
	double	ratio_y;
	double	r;
	double	i;
	double	mr;
	double	mi;
}				t_data;

int				w_error(char *str);
int				free_data(t_data *data);

void			data_setting(t_data *data);
int				set_value(t_data *data, int key);
int				init_data(t_data *data, char *name);
int				check_param(char *str);

void			draw(t_data *data, int max, int flag, char *dst);
void			fractol(t_data *data, int key, int x, int y);

int				draw_julia(double r, double i, t_data *data);
int				draw_mandelbrot(double r, double i, t_data *data);
int				draw_burningship(double r, double i, t_data *data);

int				mouse_press(int key, int x, int y, t_data *data);
int				mouse_pos(int x, int y, t_data *data);
int				x_icon(t_data *data);
int				key_press(int key, t_data *data);

#endif
