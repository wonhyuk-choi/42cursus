/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:00 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 17:28:22 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

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
	if (cub3d->image)
		mlx_destroy_image(cub3d->mlx, cub3d->image);
	if (cub3d->window)
		mlx_destroy_window(cub3d->mlx, cub3d->window);
	if (cub3d->mlx)
		free(cub3d->mlx);
	free(cub3d);
}

static char	*setting_data(t_cub3d *cub3d)
{
	int *display_x;
	int	*display_y;

	display_x = &cub3d->data->resol_x;
	display_y = &cub3d->data->resol_y;
	mlx_get_screen_size(cub3d->mlx, display_x, display_y);
	//*display_x = 1960;
	//*display_y = 800;
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
	cub3d->image = mlx_new_image(cub3d->mlx, cub3d->data->resol_x, cub3d->data->resol_y);
	cub3d->adr = mlx_get_data_addr(cub3d->image, &(cub3d->bpp), &(cub3d->leng)
	, &(cub3d->endian));
	cub3d->bpp /= 8;
	return (0);
}

char		*setting_program(t_cub3d **cub3d, char *map_path)
{
	char	*message;

	*cub3d = malloc(sizeof(t_cub3d));
	if (!*cub3d)
		return ("cub3d malloc failed");
	(*cub3d)->mlx = mlx_init();
	(*cub3d)->window = 0;
	(*cub3d)->image = 0;
	(*cub3d)->adr = 0;
	(*cub3d)->bpp = 0;
	(*cub3d)->leng = 0;
	(*cub3d)->endian = 0;
	(*cub3d)->data = 0;
	(*cub3d)->texture = 0;
	(*cub3d)->player = 0;
	(*cub3d)->data = 0;
	(*cub3d)->dda = 0;
	if (!(*cub3d)->mlx)
		return ("mlx_init failed");
	//cub3d 구조체의 변수들을 0으로 초기화한 이유는 setting_data 진행시 error가 발생한 경우 malloc이 진행되지 않은 변수들의 경우
	//쓰레기값이 남아있을 수 있어 문제가 발생할 수 있다.
	message = parse(&(*cub3d)->data, map_path);
	if (message)
		return (message);
	return (setting_data(*cub3d));
}
