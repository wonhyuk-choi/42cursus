/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:51:53 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:26:19 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	my_pixel_put(t_cub3d *cub, char *dst, char *ref)
{
	int	y;
	int	flag;
	int	*color;
	int	*point;

	y = 0;
	point = cub->dda->point;
	color = cub->data->color;
	while (y < cub->data->resol[1])
	{
		if (point[0] <= y && y <= point[1])
			*(unsigned int *)dst = t_color(ref, y - point[0], cub->dda->cur);
		else
		{
			flag = 1;
			if (y > point[1])
				flag = 0;
			*(unsigned int *)dst = (unsigned int)color[flag];
		}
		dst += cub->leng;
		y++;
	}
}

int			ray_casting(t_cub3d *cub, t_player *player, t_parse *data)
{
	int		x;
	char	*dst;

	cub->image = mlx_new_image(cub->mlx, data->resol[0], data->resol[1]);
	cub->adr = mlx_get_data_addr(cub->image, &(cub->bpp), &(cub->leng)
	, &(cub->endian));
	cub->bpp /= 8;
	x = -1;
	dst = cub->adr;
	while (++x < data->resol[0])
	{
		set_dda_value(cub->dda, player, data->resol[0], x);
		hit_wall(cub->dda, data->worldmap, player->pos);
		draw_point(cub->dda, data);
		my_pixel_put(cub, dst, select_texture(cub->texture, cub->dda));
		dst += cub->bpp;
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
	mlx_destroy_image(cub->mlx, cub->image);
	return (1);
}
