/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:20:32 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/12 02:47:26 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define XICON_PRESS 17

# include "raycasting.h"

char	*setting_program(t_cub3d *cub3d, char *map_path);
void	free_cub3d(t_cub3d *cub3d);

#endif
