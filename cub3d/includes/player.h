/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:54:56 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/11 20:03:18 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>
# include <math.h>

typedef struct	s_player
{
	double	seta;
	double	pos[2];
	double	dir[2];
	double	plane[2];
	int		key[6];
	int		i;
}				t_player;

t_player		*set_player(int *location, char dir);
char			eyesight_lr(t_player *player, double seta);
char			move_ws(t_player *player, char **worldmap, double flag);
char			move_ad(t_player *player, char **worldmap, double flag
, double pi);

#endif
