/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:15:42 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/18 20:22:20 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		dpp;
	int		sl;
	int		endian;
}				t_mlx;

#endif
