/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_one_six.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:22:22 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/04 16:01:01 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_split(t_frame *frame)
{
	if (frame->b && frame->b->value > (frame->median / 6))
		do_rb(frame);
	do_pb(frame);
}

static void	second_split(t_frame *frame)
{
	if (frame->b && frame->b->value > ((frame->median / 6) * 3))
		do_rb(frame);
	do_pb(frame);
}

static void	third_split(t_frame *frame)
{
	if (frame->b && frame->b->value > ((frame->median / 6) * 5))
		do_rb(frame);
	do_pb(frame);
}

static int	cnt_5_under(t_frame *frame, t_node *stack, int cnt)
{
	if (cnt == 1 && stack->value <= frame->median / 3)
		first_split(frame);
	else if (cnt == 2 && stack->value > (frame->median / 3)
		&& stack->value <= (frame->median / 3 * 2))
		second_split(frame);
	else if (cnt == 3 && stack->value > (frame->median / 3 * 2)
		&& stack->value <= (frame->median))
		third_split(frame);
	else if (cnt == 4 && stack->value > (frame->median)
		&& stack->value <= (frame->median / 3 * 4))
		fourth_split(frame);
	else if (cnt == 5 && stack->value > (frame->median / 3 * 4)
		&& stack->value <= (frame->median / 3 * 5))
		fifth_split(frame);
	else
		return (1);
	return (0);
}

void		push_one_six(t_frame *frame, t_node *stack, int cnt)
{
	t_node	*stack_end;
	int		flag;
	int		check;

	flag = 0;
	stack_end = frame->a->prev;
	find_small_big(frame, 'a');
	while (1)
	{
		check = 0;
		flag = (stack == stack_end) ? 1 : 0;
		if ((check = cnt_5_under(frame, stack, cnt)) == 1)
		{
			if (cnt == 6 && stack->value > (frame->median / 3 * 5))
				sixth_split(frame);
			else if (cnt == 6 && stack->value == frame->smallest)
				break ;
			else
				do_ra(frame);
		}
		if (flag == 1)
			break ;
		stack = frame->a;
	}
	reset_move_value(frame);
}
