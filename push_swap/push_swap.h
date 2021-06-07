/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:00:07 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/04 15:37:56 by wonchoi          ###   ########.fr       */
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
	int				big_flag;
	long long		smallest;
	int				small_rotate;
	int				small_rrotate;
	int				small_flag;
	long long		median;
	int				stack_len;
	int				after_rotate;
}				t_frame;

int				check_frame(t_frame *frame);
void			fill_stack_a(t_frame *frame);
void			push_swap_error(t_frame *frame);
void			push_swap_free(t_frame *frame);
void			stack_add_end(t_frame *frame, char c, long long num);
void			stack_del_top(t_frame *frame, char stack_name);
void			stack_add_top(t_frame *frame, char stack_name, long long num);

int				check_stack_len(t_frame *frame, char stack_name);

void			find_smallest(t_frame *frame, char stack_name);
void			find_biggest(t_frame *frame, char stack_name);
void			find_small_big(t_frame *frame, char stack_name);

void			median_value(t_frame *frame, char stack_name);

void			under_5(t_frame *frame);
void			under_100(t_frame *frame);
void			over_100(t_frame *frame);

void			push_median(t_frame *frame, int cnt);
void			push_one_six(t_frame *frame, t_node *stack, int cnt);

void			bottom_to_top(t_frame *frame, char stack_name, int flag);
void			top_to_bottom(t_frame *frame, char stack_name, int flag);
void			move_smallest(t_frame *frame, char stack_name);
void			move_biggest(t_frame *frame, char stack_name);
void			find_move(t_frame *frame, char stack_name);
void			reset_move_value(t_frame *frame);

void			fourth_split(t_frame *frame);
void			fifth_split(t_frame *frame);
void			sixth_split(t_frame *frame);

void			do_sa(t_frame *frame);
void			do_sb(t_frame *frame);
void			do_ss(t_frame *frame);
void			do_ra(t_frame *frame);
void			do_rb(t_frame *frame);
void			do_rr(t_frame *frame);
void			do_rra(t_frame *frame);
void			do_rrb(t_frame *frame);
void			do_rrr(t_frame *frame);
void			do_pa(t_frame *frame);
void			do_pb(t_frame *frame);

#endif
