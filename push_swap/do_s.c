/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:15:03 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/30 16:37:13 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_frame *frame)
{
	long long	tmp;

	if (frame->a && frame->a->next != frame->a)
	{
		tmp = frame->a->value;
		frame->a->value = frame->a->next->value;
		frame->a->next->value = tmp;
	}
	write(1, "sa\n", 3);
}

void	do_sb(t_frame *frame)
{
	long long	tmp;

	if (frame->b && frame->b->next != frame->b)
	{
		tmp = frame->a->value;
		frame->a->value = frame->a->next->value;
		frame->a->next->value = tmp;
	}
	write(1, "sa\n", 3);
}

void	do_ss(t_frame *frame)
{
	do_sa(frame);
	do_sb(frame);
	write(1, "ss\n", 3);
}