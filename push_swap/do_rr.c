/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:27:42 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/30 16:37:08 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_frame *frame)
{
	if (frame->a)
		frame->a = frame->a->next;
	write(1, "ra\n", 3);
}

void	do_rb(t_frame *frame)
{
	if (frame->b)
		frame->b = frame->b->next;
	write(1, "rb\n", 3);
}

void	do_rr(t_frame *frame)
{
	do_ra(frame);
	do_rb(frame);
	write(1, "rr\n", 3);
}
