/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:55:10 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:55:11 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct	s_texture
{
	void	*image;
	char	*adr;
	int		bpp;
	int		leng;
	int		endi;
	int		size[2];
	double	ratio;
}				t_texture;

t_texture		**set_texture(void *mlx, char **list);
unsigned int	t_color(char *ref, int y, t_texture *texture);
void			free_texture(t_texture **texture, void *mlx);

#endif
