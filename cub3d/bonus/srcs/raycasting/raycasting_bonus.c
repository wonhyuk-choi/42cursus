/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:51:53 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/12 02:04:07 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static void	set_minimap_pixels(t_cub3d *cub3d
, t_minimap *minimap, t_player *player)
{
	int			i;
	int			j;

	i = -1;
	while (++i < minimap->y)
	{
		j = -1;
		minimap->line = minimap->cur_img_ptr;
		while (++j < minimap->x)
		{
			if (cub3d->data->worldmap[i / 10][j / 10] == ' ')
				*minimap->line = MINIMAP_COLOR_SPACE;
			else if (cub3d->data->worldmap[i / 10][j / 10] == '1')
				*minimap->line = MINIMAP_COLOR_WALL;
			else if (cub3d->data->worldmap[i / 10][j / 10] == '2')
				*minimap->line = MINIMAP_COLOR_DOOR;
			else if (cub3d->data->worldmap[i / 10][j / 10] == '0')
				*minimap->line = MINIMAP_COLOR_ROAD;
			if (i / 10 == (int)player->pos[0] && j / 10 == (int)player->pos[1])
				*minimap->line = MINIMAP_COLOR_PLAYER;
			minimap->line++;
		}
		minimap->cur_img_ptr += minimap->texture.leng;
	}
}

static int	draw_minimap(t_cub3d *cub3d, t_player *player)
{
	t_minimap	*minimap;
	t_texture	t;

	minimap = &(cub3d->minimap);
	minimap->y = (cub3d->data->col_size + 1) * 10 + 10;
	minimap->x = (cub3d->data->row_max + 1) * 10 + 10;
	if (!(minimap->img = mlx_new_image(cub3d->mlx, minimap->x, minimap->y)))
		return (0);
	t.image = minimap->img;
	t.adr = mlx_get_data_addr(t.image, &(t.bpp), &(t.leng), &(t.endi));
	t.leng /= 4;
	minimap->cur_img_ptr = (unsigned int *)t.adr;
	minimap->texture = t;
	set_minimap_pixels(cub3d, minimap, player);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, t.image, 0, 0);
	mlx_destroy_image(cub3d->mlx, cub3d->minimap.img);
	cub3d->minimap.img = 0;
	return (1);
}

static void	my_pixel_put(t_cub3d *cub, char *dst, char *ref)
{
	int	y;
	int	flag;
	int	*color;
	int	*point;

	y = 0;
	point = cub->dda->point;
	color = cub->data->color;
	while (y < cub->data->resol_y)
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

char		ray_casting(t_cub3d *cub, t_player *player, t_parse *data)
{
	int		x;
	char	*dst;
	char	d_flag;

	cub->image = mlx_new_image(cub->mlx, data->resol_x, data->resol_y);
	if (!cub->image)
		return (0);
	cub->adr = mlx_get_data_addr(cub->image, &(cub->bpp), &(cub->leng)
	, &(cub->endian));
	cub->bpp /= 8;
	x = -1;
	dst = cub->adr;
	while (++x < data->resol_x)
	{
		set_dda_value(cub->dda, player, data->resol_x, x);
		d_flag = hit_wall(cub->dda, data->worldmap, player->pos);
		set_wall_draw_point(cub->dda, data);
		my_pixel_put(cub, dst, select_texture(cub->texture, cub->dda, d_flag));
		dst += cub->bpp;
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
	mlx_destroy_image(cub->mlx, cub->image);
	if (!draw_minimap(cub, cub->player))
		return (0);
	return (1);
}
