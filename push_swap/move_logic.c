/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:53:57 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/02 01:39:20 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_to_top(t_frame *frame, char stack_name, int flag)
{
	t_node	*tmp;
	t_node	*stack;
	int		num;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		if (stack_name == 'a')
			tmp = frame->a->prev;
		else
			tmp = frame->b->prev;
		num = (flag == 1) ? frame->smallest : frame->biggest;
		while (tmp->value != num)
		{
			flag == 1 ? (frame->small_rrotate)++ : (frame->big_rrotate)++;
			tmp = tmp->prev;
		}
		flag == 1 ? (frame->small_rrotate)++ : (frame->big_rrotate)++;
	}
}

void	top_to_bottom(t_frame *frame, char stack_name, int flag)
{
	t_node	*tmp;
	t_node	*stack;
	int		num;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? frame->a : frame->b;
		num = (flag == 1) ? frame->smallest : frame->biggest;
		while (tmp->value != num)
		{
			flag == 1 ? (frame->small_rotate)++ : (frame->big_rotate)++;
			tmp = tmp->next;
		}
	}
}

void	move_smallest(t_frame *frame, char stack_name)
{
	t_node	*stack;
	int		flag;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	flag = 1;
	if (stack)
	{
		top_to_bottom(frame, stack_name, flag);
		bottom_to_top(frame, stack_name, flag);
		if (frame->small_rotate <= frame->small_rrotate)
			frame->small_rrotate = -1;
		else
			frame->small_rotate = -1;
	}
}

void	move_biggest(t_frame *frame, char stack_name)
{
	t_node	*stack;
	int		flag;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	flag = 2;
	if (stack)
	{
		top_to_bottom(frame, stack_name, flag);
		bottom_to_top(frame, stack_name, flag);
		if (frame->big_rotate <= frame->big_rrotate)
			frame->big_rrotate = -1;
		else
			frame->big_rotate = -1;
	}
}

void	find_move(t_frame *frame, char stack_name)
{
	t_node	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	move_smallest(frame, 'b');
	move_biggest(frame, 'b');
	if (frame->big_rotate != -1 &&
		(frame->big_rotate >= frame->small_rotate
			&& frame->big_rotate >= frame->small_rrotate))
		frame->big_rotate = -1;
	else if (frame->big_rrotate != -1 &&
		(frame->big_rrotate >= frame->small_rotate
			&& frame->big_rrotate >= frame->small_rrotate))
		frame->big_rrotate = -1;
	else if (frame->small_rotate != -1 &&
		(frame->small_rotate >= frame->big_rotate
			&& frame->small_rotate >= frame->big_rrotate))
		frame->small_rotate = -1;
	else if (frame->small_rrotate != -1 &&
		(frame->small_rrotate >= frame->big_rotate
			&& frame->small_rrotate >= frame->big_rrotate))
		frame->small_rrotate = -1;
	if (frame->small_rotate != -1 || frame->small_rrotate != -1)
		frame->small_flag = 1;
	else if (frame->big_rotate != -1 || frame->big_rrotate != -1)
		frame->big_flag = 1;
}
