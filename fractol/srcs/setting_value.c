/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:21:31 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/22 18:22:44 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	ft_strcmp(char *s1, char *s2, int leng)
{
	int	i;

	i = 0;
	while (i < leng && *(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i++;
	}
	if (i == leng && !*(s1 + i) && !*(s2 + i))
		return (1);
	return (0);
}

void		data_setting(t_data *data)
{
	data->zoom = 4;
	data->ratio_x = data->zoom / (double)data->w;
	data->ratio_y = data->zoom / (double)data->h;
	data->r = -data->zoom * 0.5;
	data->i = -data->zoom * 0.5;
	data->mr = 0;
	data->mi = 0;
	data->max = 100;
	data->color_range = 0;
}

int			set_value(t_data *data, int key)
{
	double	num;

	num = 1;
	if (key == 4)
		num = 1.2;
	else if (key == 5)
		num = 0.8;
	data->zoom *= num;
	data->ratio_x *= num;
	data->ratio_y *= num;
	data->r = -data->zoom * 0.5;
	data->i = -data->zoom * 0.5;
	if (!(data->image = mlx_new_image(data->mlx, data->w, data->h)))
		return (0);
	data->adr = mlx_get_data_addr(data->image, &(data->bpp)
		, &(data->len), &(data->endian));
	data->bpp /= 8;
	return (1);
}

int			init_data(t_data *data, char *name)
{
	if (!(data->mlx = mlx_init()))
		return (0);
	data->win = 0;
	data->image = 0;
	data->w = 1000;
	data->h = 800;
	data->win = mlx_new_window(data->mlx, data->w, data->h, name);
	if (!data->win)
		return (free_data(data));
	data->fractol = *name;
	data_setting(data);
	return (1);
}

int			check_param(char *str)
{
	int	check;

	check = 0;
	while (*(str + check))
		check++;
	if (ft_strcmp(str, "Julia", check))
		return (1);
	else if (ft_strcmp(str, "Mandelbrot", check))
		return (1);
	else if (ft_strcmp(str, "Burningship", check))
		return (1);
	return (0);
}
