/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:33:40 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/30 14:39:56 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_len(t_frame *frame, char stack_name)
{
	t_node	*stack;
	t_node	*save;
	int		len;

	len = 0;
	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	if (stack && stack_name == 'a')
		save = frame->a->prev;
	else
		save = frame->b->prev;
	while (stack)
	{
		len++;
		if (stack == save)
			break ;
		stack = stack->next;
	}
	return (len);
}
