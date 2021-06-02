/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:27:42 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/02 01:38:49 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_frame *frame)
{
	if (frame->a)
		frame->a = frame->a->prev;
	write(1, "rra\n", 4);
}

void	do_rrb(t_frame *frame)
{
	if (frame->b)
		frame->b = frame->b->prev;
	write(1, "rrb\n", 4);
}

void	do_rrr(t_frame *frame)
{
	do_rra(frame);
	do_rrb(frame);
	write(1, "rrr\n", 4);
}