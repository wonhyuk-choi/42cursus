/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_small_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:25:59 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/02 01:39:05 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest(t_frame *frame, char stack_name)
{
	t_node	*stack;
	t_node	*tmp;
	t_node	*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	frame->smallest = frame->biggest;
	while (1)
	{
		if (tmp->value <= frame->smallest)
			frame->smallest = tmp->value;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest(t_frame *frame, char stack_name)
{
	t_node	*stack;
	t_node	*tmp;
	t_node	*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	frame->biggest = tmp->value;
	end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	while (1)
	{
		if (tmp->value > frame->biggest)
			frame->biggest = tmp->value;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_small_big(t_frame *frame, char stack_name)
{
	find_biggest(frame, stack_name);
	find_smallest(frame, stack_name);
}