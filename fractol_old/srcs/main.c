/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:36:55 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/18 00:44:29 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*win_init(char *name)
{
	t_image	*image;

	if (!(image = malloc(sizeof(t_image))))
		return (NULL);
	image->mlx = mlx_init();
	image->win_w = 800;
	image->win_h = 500;
	image->win = mlx_new_window(image->mlx, image->win_w, image->win_h, name);
	image->ptr = mlx_new_image(image->mlx, image->win_w, image->win_h);
	image->adr = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->len, &image->endian);
	image->bpp /= 8;
	return (image);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->im.x = 0;
	fractol->im.y = 0;
	fractol->img_h = WIN_HEIGHT / 2;
	fractol->img_w = WIN_WIDTH / 2;
	fractol->zoom = 100;
	fractol->iter_max = 50;
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2)
		return (1);
	if (!(fractol = malloc(sizeof(t_fractol))))
		return (1);
	fractol->image = win_init(argv[1]);
	if (!(check_fractol(argv[1], fractol)))
		return (1);
	init_fractol(fractol);
	draw(fractol);
	mlx_put_image_to_window(fractol->image->mlx, fractol->image->win,
		fractol->image->ptr, 0, 0);
	mlx_hook(fractol->image->win, 6, 0, julia_move, fractol);
	mlx_hook(fractol->image->win, 4, 0, mouse_move, fractol);
	mlx_hook(fractol->image->win, 17, 0, x_icon, fractol);
	mlx_key_hook(fractol->image->win, key_hook, fractol);
	mlx_loop(fractol->image->mlx);
}
