/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:49:26 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/01 19:22:00 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_frame	*create_frame(t_frame *frame, char **argv)
{
	if (!(frame = malloc(sizeof(t_frame))))
		exit(1);
	frame->a = NULL;
	frame->b = NULL;
	frame->argv = argv;
	frame->biggest = 0;
	frame->smallest = 0;
	frame->big_rotate = 0;
	frame->big_rrotate = 0;
	frame->small_rotate = 0;
	frame->small_rrotate = 0;
	frame->stack_len = 0;
	frame->quarter_1 = 0;
	frame->median = 0;
	frame->quarter_3 = 0;
	frame->after_rotate = 0;
	frame->big_flag = 0;
	frame->small_flag = 0;
	return (frame);
}

void	solve_fn(t_frame *frame)
{
	if (check_stack_len(frame, 'a') <= 5)
		under_5(frame);
	else if (check_stack_len(frame, 'a') <= 100)
		under_100(frame);
}

int	check_frame(t_frame *frame)
{
	t_node	*tmp;

	if (!frame->a || frame->b)
		return (0);
	tmp = frame->a;
	while (tmp->next != frame->a)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	push_swap(t_frame *frame)
{
	fill_stack_a(frame);
	if (!check_frame(frame))
	{
		solve_fn(frame);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_frame	*frame;
	t_node	*test;

	frame = NULL;
	if (argc < 2)
	{
		push_swap_error(frame);
		return (1);
	}
	frame = create_frame(frame, argv);
	push_swap(frame);
	return (0);
}
