/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:58:20 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/01 14:35:37 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_frame *frame)
{
	long long	num;

	if (frame->b)
	{
		num = frame->b->value;
		stack_del_top(frame, 'b');
		stack_add_top(frame, 'a', num);
	}
	write(1, "pa\n", 3);
}

void	do_pb(t_frame *frame)
{
	long long	num;

	if (frame->a)
	{
		num = frame->a->value;
		stack_del_top(frame, 'a');
		stack_add_top(frame, 'b', num);
	}
	write(1, "pb\n", 3);
}
