/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:59:50 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/02 01:40:11 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_2(t_frame *frame)
{
	if (frame->a->value > frame->a->next->value)
		do_sa(frame);
}

static void	solve_3(t_frame *frame)
{
	t_node	*stack_a;
	t_node	*tmp;

	find_biggest(frame, 'a');
	bottom_to_top(frame, 'a', 2);
	if (frame->big_rrotate >= 1)
		while (frame->big_rrotate-- > 1)
			do_rra(frame);
	stack_a = frame->a;
	tmp = frame->a->next;
	if (stack_a->value > tmp->value)
		do_sa(frame);
}

static void	solve_4(t_frame *frame)
{
	t_node	*stack_a;

	stack_a = frame->a;
	find_small_big(frame, 'a');
	while (stack_a->value != frame->smallest)
	{
		do_ra(frame);
		stack_a = stack_a->next;
	}
	do_pb(frame);
	solve_3(frame);
	do_pa(frame);
}

static void	solve_5(t_frame *frame)
{
	t_node	*a_stack_end;
	t_node	*tmp;
	int		flag;

	flag = 0;
	a_stack_end = frame->a->prev;
	median_value(frame, 'a');
	while (flag != 1)
	{
		flag = frame->a == a_stack_end ? 1 : 0;
		if (frame->a->value < frame->median)
			do_pb(frame);
		else
			do_ra(frame);
	}
	solve_3(frame);
	tmp = frame->b->next;
	if (frame->b->value < tmp->value)
		do_sb(frame);
	do_pa(frame);
	do_pa(frame);
}

void		under_5(t_frame *frame)
{
	if (check_stack_len(frame, 'a') == 2)
		solve_2(frame);
	else if (check_stack_len(frame, 'a') == 3)
		solve_3(frame);
	else if (check_stack_len(frame, 'a') == 4)
		solve_4(frame);
	else
		solve_5(frame);
}
