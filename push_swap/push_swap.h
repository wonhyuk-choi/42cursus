/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:00:07 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/30 19:32:25 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_node
{
	long long		value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_frame
{
	struct s_node	*a;
	struct s_node	*b;
	char			**argv;
	long long		biggest;
	int				big_rotate;
	int				big_rrotate;
	long long		smallest;
	int				small_rotate;
	int				small_rrotate;
}				t_frame;

void	fill_stack_a(t_frame *frame);
void	push_swap_error(t_frame *frame);
void	stack_add_end(t_frame *frame, char c, long long num);
void	stack_del_top(t_frame *frame, char stack_name);
void	stack_add_top(t_frame *frame, char stack_name, int num);

int		check_stack_len(t_frame *frame, char stack_name);

void	find_smallest(t_frame *frame, char stack_name);
void	find_biggest(t_frame *frame, char stack_name);
void	find_small_big(t_frame *frame, char stack_name);

void	under_5(t_frame *frame);
void	under_100(t_frame *frame);
void	up_100(t_frame *frame);

void	move_bottom(t_frame *frame, char stack_name, int flag);

void	do_sa(t_frame *frame);
void	do_sb(t_frame *frame);
void	do_ss(t_frame *frame);
void	do_ra(t_frame *frame);
void	do_rb(t_frame *frame);
void	do_rr(t_frame *frame);
void	do_rra(t_frame *frame);
void	do_rrb(t_frame *frame);
void	do_rrr(t_frame *frame);
void	do_pa(t_frame *frame);
void	do_pb(t_frame *frame);

#endif