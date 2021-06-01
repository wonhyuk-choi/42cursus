/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:26:00 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/01 15:59:07 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	array_sort(long long *array, int len)
{
	long long	tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

static void	find_median_value(t_frame *frame, t_node *stack, char stack_name)
{
	long long	*array;
	int			i;
	int			quarter_len;

	i = 0;
	frame->stack_len = check_stack_len(frame, stack_name);
	quarter_len = frame->stack_len / 4;
	if (!(array = malloc(sizeof(long long) * frame->stack_len)))
		push_swap_error(frame);
	while (i < frame->stack_len)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	array_sort(array, frame->stack_len);
	frame->quarter_1 = array[quarter_len];
	frame->median = array[quarter_len * 2];
	frame->quarter_3 = array[quarter_len * 3];
	free(array);
}

void	median_value(t_frame *frame, char stack_name)
{
	t_node	*stack;

	stack = (stack_name == 'a') ? frame->a : frame ->b;
	find_median_value(frame, stack, stack_name);
}
