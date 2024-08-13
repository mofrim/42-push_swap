/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:35:30 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/13 21:29:04 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWP_H
# define PUSH_SWP_H

typedef struct s_stack
{
	long	*st;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	long	*sortd;
	int		initial_size;
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
void		pa(t_stacks **st);
void		pb(t_stacks **st);
void		ra(t_stacks **st);
void		rb(t_stacks **st);
void		rr(t_stacks **st);
void		rra(t_stacks **st);
void		rrr(t_stacks **st);

/* Ops with printing. */
void		pa_print(t_stacks **st);
void		pb_print(t_stacks **st);
void		ra_print(t_stacks **st);
void		rb_print(t_stacks **st);
void		rr_print(t_stacks **st);
void		rra_print(t_stacks **st);
void		rrr_print(t_stacks **st);

#endif 
