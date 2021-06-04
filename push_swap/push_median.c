/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:31:07 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/02 01:39:27 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_median(t_frame *frame, int cnt)
{
	t_node	*stack;
	t_node	*stack_end;
	int		flag;

	flag = 0;
	stack_end = frame->a->prev;
	stack = frame->a;
	find_smallest(frame, 'a');
	while (1)
	{
		if (stack == stack_end)
			flag = 1;
		if (cnt == 1 && stack->value <= frame->median)
			do_pb(frame);
		else if (cnt == 2 && stack->value > frame->median)
			do_pb(frame);
		else if (stack->value == frame->smallest)
			break ;
		else
			do_ra(frame);
		if (flag == 1)
			break ;
		stack = frame->a;
	}
	reset_move_value(frame);
}
