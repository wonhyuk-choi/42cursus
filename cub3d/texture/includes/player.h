/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:54:56 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:06:42 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>
# include <math.h>
# define PIT 3.14 / 180

typedef struct	s_player
{
	double	fov;
	double	pos[2];
	double	dir[2];
	double	plane[2];
	int		key[6];
}				t_player;

t_player		*set_player(int *location, char dir);
char			eyesight_lr(t_player *player, double seta);
char			move_ws(t_player *player, char **worldmap, double flag);
char			move_ad(t_player *player, char **worldmap, double flag);

#endif
