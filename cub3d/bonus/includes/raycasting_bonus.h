/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:55:02 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 22:13:57 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# define MINIMAP_COLOR_SPACE 0x0091e0f4
# define MINIMAP_COLOR_WALL 0x000c90ad
# define MINIMAP_COLOR_DOOR 0x00b7b7b7
# define MINIMAP_COLOR_ROAD 0x00f8f1f9
# define MINIMAP_COLOR_PLAYER 0x000c90ad

# include "parse_bonus.h"
# include "player_bonus.h"
# include "texture_bonus.h"

typedef struct	s_minimap
{
	int				y;
	int				x;
	char			*img;
	unsigned int	*cur_img_ptr;
	unsigned int	*line;
	t_texture		texture;
}				t_minimap;

typedef struct	s_dda
{
	int			map[2];
	int			point[2];
	int			side;
	double		ray[2];
	double		wall_x;
	double		sidedist[2];
	double		deltadist[2];
	double		step[2];
	double		walldist;
	t_texture	*cur;
}				t_dda;

typedef struct	s_cub3d
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*adr;
	int			bpp;
	int			leng;
	int			endian;
	t_texture	**texture;
	t_player	*player;
	t_parse		*data;
	t_dda		*dda;
	t_minimap	minimap;
}				t_cub3d;

char			ray_casting(t_cub3d *cub3d, t_player *player, t_parse *data);

int				mouse_pos(int x, int y, t_cub3d *cub3d);
int				x_icon(t_cub3d *cub3d);
int				key_press(int keycode, t_cub3d *cub3d);
int				key_release(int keycode, t_cub3d *cub3d);
int				active_apply(t_cub3d *cub3d);

void			set_wall_draw_point(t_dda *dda, t_parse *data);
void			set_dda_value(t_dda *dda, t_player *player, int resolution
, int x);
char			hit_wall(t_dda *dda, char **map, double *pos);
char			*select_texture(t_texture **texture, t_dda *dda
, char door_flag);

#endif
