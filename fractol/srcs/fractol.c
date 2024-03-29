/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:40:27 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/22 18:29:06 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	run_program(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_press, data);
	mlx_hook(data->win, 6, 0, mouse_pos, data);
	mlx_hook(data->win, 17, 0, x_icon, data);
	mlx_key_hook(data->win, key_press, data);
	mlx_loop(data->mlx);
}

int			w_error(char *str)
{
	ft_putstr_fd(str, 1);
	write(2, "\n", 1);
	return (1);
}

int			free_data(t_data *data)
{
	if (!data)
		return (0);
	if (data->image)
		mlx_destroy_image(data->mlx, data->image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	if (data)
		free(data);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2 && check_param(*(++argv)))
	{
		if (!(data = malloc(sizeof(t_data))))
			return (w_error("fractol malloc error"));
		if (!init_data(data, *argv))
			return (w_error("init_data error"));
		fractol(data, 0, -1, -1);	
		run_program(data);
	}
	return (w_error("./fractol list\n1. Julia\n2. Mandelbrot\n3. Burningship"));
}
