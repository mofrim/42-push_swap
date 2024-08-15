/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:35:30 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 11:58:38 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWP_H
# define PUSH_SWP_H

typedef struct s_stack
{
	long	*st;
	int		size;
}	t_stack;

/* cur_min: the index in sortd-array of current minimal value. */
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	long	*sortd;
	int		initial_size;
	int		cur_min;
}	t_stacks;

t_stacks	*init_stacks(int size);
void		fill_stack_rand(t_stacks **st, unsigned int seed);
void		fill_stack_rev(t_stacks **st);
void		free_stacks(t_stacks **st);
void		print_stacks(t_stacks *st);

void		simple_sort(t_stacks **sts);
void		simple_sort2(t_stacks **sts);
void		swap_sort(t_stacks **sts);
void		bring_min_to_top(t_stacks **sts);
void		bring_max_to_top(t_stacks **sts, int size);

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
void		sa_print(t_stacks **st);
void		sb_print(t_stacks **st);
void		ss_print(t_stacks **st);
void		pa_print(t_stacks **st);
void		pb_print(t_stacks **st);
void		ra_print(t_stacks **st);
void		rb_print(t_stacks **st);
void		rr_print(t_stacks **st);
void		rra_print(t_stacks **st);
void		rrb_print(t_stacks **st);
void		rrr_print(t_stacks **st);

/* stratsort. */
void		stratsort(t_stacks **sts);
t_stacks	*stacks_dup(t_stacks *orig);
void		sort2(t_stacks **sts);
void		sort3(t_stacks **sts);
int			strat1_sim(t_stacks *sts);
int			strat2_sim(t_stacks *sts);
int			strat3_sim(t_stacks *sts);
int			strat1_do(t_stacks **sts);
int			strat2_do(t_stacks **sts);
int			strat3_do(t_stacks **sts);
int			move_top_min(t_stacks **sts, int min_offset);

#endif 
