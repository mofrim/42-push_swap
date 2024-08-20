/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:35:30 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 12:02:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWP_H
# define PUSH_SWP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <errno.h>

typedef struct s_stack
{
	long	*st;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		*dsts_a;
	int		*dsts_b;
	int		*targets;
	int		initial_size;
}	t_stacks;

t_stacks	*init_stacks(int size);
t_stacks	*init_stacks_rand(int size, int seed);
t_stacks	*init_stacks_empty(int size);
void		fill_stack_rand(t_stacks **st, unsigned int seed);
void		fill_stack_rev(t_stacks **st);
void		free_stacks(t_stacks **st);
void		print_stacks(t_stacks *st);

void		quicksort(long **arr, int low, int high);
long		*quicksorted_stack(long *arr, int size);
int			get_index_sorted(long num, long *sorted_stack, int size);
void		move_to_top_next(t_stacks **sts, long *ss, long xi, int stack_size);

/* Operations. */
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

/* utils. */
long		ft_abs(long num);
void		exit_error_malloc(void);
int			get_min_indx(t_stack *s);
int			get_max_indx(t_stack *s);
long		get_stack_max(t_stack *stck);
int			move_top_min_smart(t_stacks **sts);

/* smartsort. */

int			smartsort(t_stacks **sts);
int			pb_all_but_three(t_stacks **sts);
int			sort_three(t_stacks **sts);
void		reset_dsts(t_stacks **sts);
void		set_targets(t_stacks **sts);
int			get_target(long elem, t_stack *s, int size);
void		print_dsts_trgts(t_stacks *sts);
void		calc_dsts(t_stacks **sts);
int			find_best_move(t_stacks **sts);
int			do_best_move(t_stacks **sts, int best);

#endif 
