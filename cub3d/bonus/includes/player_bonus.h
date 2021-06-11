/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:54:56 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 17:00:22 by taewakim         ###   ########.fr       */
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
	int		key[8];
}				t_player;

t_player		*set_player(int *location, char dir);
char			eyesight_lr(t_player *player, double seta);
char			move_ws(t_player *player, char **worldmap, double flag);
char			move_ad(t_player *player, char **worldmap, double flag, double pi);
char			change_door_state(t_player *player, char **worldmap);

#endif
