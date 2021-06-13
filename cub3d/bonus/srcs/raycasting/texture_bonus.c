/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:24 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/12 01:58:48 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_bonus.h"

static char		set_texture_img(t_texture *t, char *list, void *mlx)
{
	t->image = mlx_png_file_to_image(mlx, list, &t->size[0]
	, &t->size[1]);
	if (!t->image)
		return (0);
	t->adr = mlx_get_data_addr(t->image, &(t->bpp), &(t->leng)
	, &(t->endi));
	t->bpp /= 8;
	return (1);
}

t_texture		**set_texture(void *mlx, char **list)
{
	int			i;
	t_texture	**t;

	t = (t_texture **)malloc(sizeof(t_texture *) * 6);
	if (!t)
		return (0);
	i = 6;
	while (--i >= 0)
		t[i] = 0;
	while (++i < 5)
	{
		t[i] = malloc(sizeof(t_texture));
		if (!t[i])
			return (0);
		if (!set_texture_img(t[i], list[i], mlx))
		{
			free_texture(t, mlx);
			return (0);
		}
	}
	return (t);
}

unsigned int	t_color(char *ref, int y, t_texture *texture)
{
	char	*result;

	result = ref + (int)(y * texture->ratio) * texture->leng;
	return (*(unsigned int *)result);
}

void			free_texture(t_texture **texture, void *mlx)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		if (texture[i]->image)
			mlx_destroy_image(mlx, texture[i]->image);
		free(texture[i]);
		i++;
	}
	free(texture);
	texture = 0;
}
