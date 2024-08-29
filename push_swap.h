/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:35:30 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 14:40:31 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"

/* Struct for the individual stacks A and B. */
typedef struct s_stack
{
	long	*st;
	int		size;
}	t_stack;

/* The mother struct. Keeping Stacks A and B and all auxiliary vars. */
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		*dsts_a;
	int		*dsts_b;
	int		*targets;
	int		initial_size;
}	t_stacks;

/* Stack funcs. */
t_stacks	*init_stacks(int size);
t_stacks	*init_stacks_with_args(long **args, int size);
void		fill_stack_rand(t_stacks **st, unsigned int seed);
void		free_stacks(t_stacks **st);
void		print_stacks(t_stacks *st);

/* Ops. */
int			sa(t_stacks **st);
int			sb(t_stacks **st);
int			ss(t_stacks **st);
int			pa(t_stacks **st);
int			pb(t_stacks **st);
int			ra(t_stacks **st);
int			rb(t_stacks **st);
int			rr(t_stacks **st);
int			rra(t_stacks **st);
int			rrb(t_stacks **st);
int			rrr(t_stacks **st);

/* Ops with printing. */
int			sa_print(t_stacks **st);
int			sb_print(t_stacks **st);
int			ss_print(t_stacks **st);
int			pa_print(t_stacks **st);
int			pb_print(t_stacks **st);
int			ra_print(t_stacks **st);
int			rb_print(t_stacks **st);
int			rr_print(t_stacks **st);
int			rra_print(t_stacks **st);
int			rrb_print(t_stacks **st);
int			rrr_print(t_stacks **st);

/* Utils. */
int			is_dupl(long n, long *arr, int size);
int			is_sorted(long *arr, int size);
long		ps_abs(long num);
long		ps_atol(const char *s);
int			get_indx_of_stack_min(t_stack *s);
int			get_indx_of_stack_max(t_stack *s);
void		move_top_min_smart(t_stacks **sts);
void		exit_error_malloc(void);
void		exit_error_arg(void);
void		exit_error_malloc_free_stacks(t_stacks **sts);

/* Smartsort. */
void		smartsort(t_stacks **sts);
void		pb_all_but_three_small(t_stacks **sts);
void		pb_all_but_three_big(t_stacks **sts);
void		reset_dsts(t_stacks **sts);
int			decrement_dst(int *dst);
void		set_targets(t_stacks **sts);
int			get_target(long elem, t_stack *s, int size);
void		print_dsts_trgts(t_stacks *sts);
void		calc_dsts(t_stacks **sts);
int			find_best_move(t_stacks **sts);
int			do_best_move(t_stacks **sts, int best);
long		*get_quicksorted_stack_a(t_stacks **sts, int size);

#endif 
