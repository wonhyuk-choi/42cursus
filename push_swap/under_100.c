/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:31:30 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/02 12:22:03 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_push_a(t_frame *frame)
{
	if (frame->small_rotate >= 0)
		while (frame->small_rotate--)
			do_rb(frame);
	else if (frame->small_rrotate >= 0)
		while (frame->small_rrotate--)
			do_rrb(frame);
	else if (frame->big_rotate >= 0)
		while (frame->big_rotate--)
			do_rb(frame);
	else if (frame->big_rrotate >= 0)
		while (frame->big_rrotate--)
			do_rrb(frame);
	do_pa(frame);
	frame->small_flag == 1 ? do_ra(frame) : 0;
	(frame->big_flag == 1 || !frame->b) ? frame->after_rotate++ : 0;
	reset_move_value(frame);
}

static void	before_push_a(t_frame *frame, t_node *stack, t_node *stack_end)
{
	while (1)
	{
		while (stack->value != frame->smallest
			&& stack->value != frame->biggest)
			stack = stack->next;
		if (stack->value == frame->smallest
			|| stack->value == frame->biggest)
		{
			rotate_push_a(frame);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = frame->b;
	}
}

void		under_100(t_frame *frame)
{
	int	cnt;

	cnt = 1;
	median_value(frame, 'a');
	while (frame->a)
	{
		push_median(frame, cnt);
		while (frame->b)
		{
			find_small_big(frame, 'b');
			find_move(frame, 'b');
			if (frame->b && (frame->small_rotate >= 0
					|| frame->small_rrotate >= 0 || frame->big_rotate >= 0
					|| frame->big_rrotate >= 0))
				before_push_a(frame, frame->b, frame->b->prev);
		}
		while (--frame->after_rotate)
			do_ra(frame);
		cnt++;
		if (cnt == 3)
			break ;
	}
}
