/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:53:57 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/30 17:24:15 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_bottom(t_frame *frame, char stack_name, int flag)
{
	t_node  *tmp;
	t_node  *stack;
	int     num;

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
