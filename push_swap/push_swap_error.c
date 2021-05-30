/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 00:42:10 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/30 12:13:48 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_all(t_node *node)
{
	t_node	*next_node;
	t_node	*del;	

	if (node)
	{
		next_node = node->next;
		while (node->next != node)
		{
			del = next_node;
			next_node = node->next;
			free(del);
		}
		free(next_node);
	}
}

static void	free_frame(t_frame *frame)
{
	if (frame->a)
		free_all(frame->a);
	free(frame);
}

void	push_swap_free(t_frame *frame)
{
	free_frame(frame);
}

void	push_swap_error(t_frame *frame)
{
	write(2, "Error\n", 6);
	push_swap_free(frame);
	exit(1);
}
