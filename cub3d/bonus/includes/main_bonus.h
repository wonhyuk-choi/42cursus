/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:17:37 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/12 02:13:47 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_MOVE 6
# define XICON_PRESS 17

# include "raycasting_bonus.h"

char	*setting_program(t_cub3d *cub3d, char *map_path);
void	free_cub3d(t_cub3d *cub3d);

#endif
