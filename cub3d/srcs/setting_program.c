/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:00 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/12 02:49:48 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->texture)
		free_texture(cub3d->texture, cub3d->mlx);
	if (cub3d->data)
		free_data(cub3d->data);
	if (cub3d->dda)
		free(cub3d->dda);
	if (cub3d->player)
		free(cub3d->player);
	if (cub3d->window)
		mlx_destroy_window(cub3d->mlx, cub3d->window);
}

static char	*setting_data(t_cub3d *cub3d)
{
	int *display_x;
	int	*display_y;

	display_x = &cub3d->data->resol_x;
	display_y = &cub3d->data->resol_y;
	mlx_get_screen_size(cub3d->mlx, display_x, display_y);
	*display_x = 1000;
	*display_y = 800;
	cub3d->window = mlx_new_window(cub3d->mlx, *display_x, *display_y, "cub3d");
	if (!cub3d->window)
		return ("mlx_new_window failed");
	cub3d->texture = set_texture(cub3d->mlx, cub3d->data->texture_path);
	if (!cub3d->texture)
		return ("set_texture failed");
	cub3d->player = set_player(cub3d->data->location, cub3d->data->direction);
	if (!cub3d->player)
		return ("set_player failed");
	cub3d->dda = malloc(sizeof(t_dda));
	if (!cub3d->dda)
		return ("dda malloc failed");
	return (0);
}

char		*setting_program(t_cub3d *cub3d, char *map_path)
{
	char	*message;

	cub3d->mlx = mlx_init();
	cub3d->window = 0;
	cub3d->image = 0;
	cub3d->adr = 0;
	cub3d->bpp = 0;
	cub3d->leng = 0;
	cub3d->endian = 0;
	cub3d->data = 0;
	cub3d->texture = 0;
	cub3d->player = 0;
	cub3d->data = 0;
	cub3d->dda = 0;
	if (!cub3d->mlx)
		return ("mlx_init failed");
	message = parse(&cub3d->data, map_path);
	if (message)
		return (message);
	return (setting_data(cub3d));
}
