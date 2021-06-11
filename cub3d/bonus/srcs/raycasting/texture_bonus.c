/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:24 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:52:24 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_bonus.h"

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
		t[i]->image = mlx_png_file_to_image(mlx, list[i], &t[i]->size[0], &t[i]->size[1]);
		if (!t[i]->image)
		{
			free_texture(t, mlx);
			return (0);
		}
		t[i]->adr = mlx_get_data_addr(t[i]->image, &(t[i]->bpp), &(t[i]->leng), &(t[i]->endi));
		t[i]->bpp /= 8;
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
}
