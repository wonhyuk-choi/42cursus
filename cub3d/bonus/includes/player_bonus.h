/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:54:56 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 20:49:06 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include <stdlib.h>
# include <math.h>

typedef struct	s_player
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	seta;
	int		i;
	int		key[8];
	int		location_x;
	char	mouse_switch;
}				t_player;

t_player		*set_player(int *location, char dir, int x);
char			eyesight_lr(t_player *player, double seta);
char			move_ws(t_player *player, char **worldmap, double flag);
char			move_ad(t_player *player, char **worldmap, double flag
, double pi);
char			change_door_state(t_player *player, char **worldmap);
char			rotate_mouse(t_player *player, double pi);

#endif
