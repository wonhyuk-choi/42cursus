/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_move_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:40:15 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/01 19:42:52 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_move_value(t_frame *frame)
{
	frame->biggest = 0;
	frame->big_flag = 0;
	frame->big_rotate = 0;
	frame->big_rrotate = 0;
	frame->small_flag = 0;
	frame->small_rotate = 0;
	frame->small_rrotate = 0;
	frame->smallest = 0;
}