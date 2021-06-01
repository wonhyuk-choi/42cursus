/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:43:59 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/01 14:38:41 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_end(t_frame *frame, char c, long long num)
{
	t_node  **top;
	t_node  *tmp;

	if (c == 'a')
		top = &frame->a;
	else
		top = &frame->b;
	if (*top)
	{
		if (!(tmp = malloc(sizeof(t_node))))
			push_swap_error(frame);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->value = num;
	}
	else
	{
		if (!(*top = malloc(sizeof(t_node))))
			push_swap_error(frame);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->value = num;
	}
}

void    stack_add_top(t_frame *frame, char stack_name, long long num)
{
	t_node	**top;
	t_node	*tmp;

	top = (stack_name == 'a') ? &frame->a : &frame->b;
	if (*top)
	{
		if (!(tmp = malloc(sizeof(t_node))))
			push_swap_error(frame);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->value = num;
		*top = (*top)->prev;
	}
	else
	{
		if (!(*top = malloc(sizeof(t_node))))
			push_swap_error(frame);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->value = num;
	}
}

void	stack_del_top(t_frame *frame, char stack_name)
{
	t_node	**top;
	t_node	*tmp;

	top = (stack_name == 'a') ? &frame->a : &frame->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->prev->next = *top;
			(*top)->prev = tmp->prev;
			free(tmp);
		}
	}
}
