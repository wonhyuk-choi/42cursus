/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_one_six_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:22:22 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/04 14:30:38 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fourth_split(t_frame *frame)
{
	if (frame->b && frame->b->value > ((frame->median / 6) * 7))
		do_rb(frame);
	do_pb(frame);
}

void	fifth_split(t_frame *frame)
{
	if (frame->b && frame->b->value > (frame->median / 6 * 9))
		do_rb(frame);
	do_pb(frame);
}

void	sixth_split(t_frame *frame)
{
	if (frame->b && frame->b->value > (frame->median / 6 * 11))
		do_rb(frame);
	do_pb(frame);
}
