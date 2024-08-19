/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:17:40 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 10:46:26 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"

/* func for updating sortd array in each stack. reverse sortd array in stack b.
 */
void	update_sortd_both(t_stacks **sts)
{
	if ((*sts)->a->sortd)
		free((*sts)->a->sortd);
	if ((*sts)->b->sortd)
		free((*sts)->b->sortd);
	(*sts)->a->sortd = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
	(*sts)->b->sortd = quicksorted_stack((*sts)->b->st, (*sts)->b->size);
	inv_long_arr(&(*sts)->b->sortd, (*sts)->b->size);
}

/* update sortd in single stack */
void	update_sortd_single(t_stack **st)
{
	if ((*st)->sortd)
		free((*st)->sortd);
	(*st)->sortd = quicksorted_stack((*st)->st, (*st)->size);
}

/* WARN: need to update_sortd before doing this! 
 * INFO: for now doing it inside this function.. oh god! so many operations.
 *
 * TODO: maybe make this start from min elem. and then somehow overflow when
 * reaching the end of array to start comparing from arr beginning again.
 *
 */
int	is_stack_sorted(t_stack **stck)
{
	int	indx;
	int	cnt;

	indx = get_min_indx(*stck);
	update_sortd_single(stck);
	cnt = 0;
	while (cnt < (*stck)->size)
	{
		if (indx == (*stck)->size)
			indx = 0;
		if ((*stck)->st[indx] != (*stck)->sortd[cnt])
			return (0);
		indx++;
		cnt++;
	}
	return (1);
}
int	is_stack_sorted_rev(t_stack **stck)
{
	int	indx;
	int	cnt;

	indx = get_max_indx(*stck);
	update_sortd_single(stck);
	inv_long_arr(&(*stck)->sortd, (*stck)->size);
	cnt = 0;
	while (cnt < (*stck)->size)
	{
		if (indx == (*stck)->size)
			indx = 0;
		// ft_printf("(*stck)->st[indx]: %d, (*stck)->sortd[cnt]: %d'\n",(*stck)->st[indx], (*stck)->sortd[cnt]);
		if ((*stck)->st[indx] != (*stck)->sortd[cnt])
			return (0);
		indx++;
		cnt++;
	}
	return (1);
}

/* FUcking fuck! this is unreadable! NEED TO UPDATE SORTD BEFORE RUNNING THIS!!!
 */
int	swap_sort_single(t_stacks **sts)
{
	long	*st;
	int		size;
	long	min;
	long	max;
	int		ops;

	st = (*sts)->a->st;
	size = (*sts)->a->size;
	update_sortd_single(&(*sts)->a);
	min = (*sts)->a->sortd[0];
	max = (*sts)->a->sortd[size - 1];

	// oh yeah. you can do wayyy better, huh?!
	if (size < 4)
		return (0);

	ops = 0;
	while (!is_stack_sorted(&(*sts)->a))
	{
		if (st[0] > st[1] && !(st[0] == max && st[1] == min))
			ops += sa_print(sts);
		ops += ra_print(sts);
	}
	return (ops);
}

int	swap_sort_rev_single(t_stacks **sts)
{
	long	*st;
	int		size;
	long	min;
	long	max;
	int		ops;

	st = (*sts)->b->st;
	size = (*sts)->b->size;
	update_sortd_single(&(*sts)->b);
	inv_long_arr(&(*sts)->b->sortd, size);
	max = (*sts)->b->sortd[0];
	min = (*sts)->b->sortd[size - 1];

	// TODO: catch or handle minimum size here or before func call.
	if (size < 2)
		return (0);

	ops = 0;
	while (!is_stack_sorted_rev(&(*sts)->b))
	{
		if (st[0] < st[1] && !(st[0] == min && st[1] == max ))
			ops += sb_print(sts);
		ops += rb_print(sts);
		// print_stacks(*sts);
	}
	return (ops);
}

int	swap_sort_simul(t_stacks **sts)
{
	t_stack	*a;
	t_stack	*b;
	int		ops;

	a = (*sts)->a;
	b = (*sts)->b;
	update_sortd_both(sts);
	ops = 0;
	while(!is_stack_sorted(&(*sts)->a) || !is_stack_sorted_rev(&(*sts)->b))
	{
		if ((a->st[0] > a->st[1] && !(a->st[0] == a->sortd[a->size - 1] && a->st[1] == a->sortd[0])) && \
				(b->st[0] < b->st[1] && !(b->st[0] == b->sortd[a->size - 1] && b->st[1] == a->sortd[0])))
			ops += ss_print(sts);
		else if (a->st[0] > a->st[1] && !(a->st[0] == a->sortd[a->size - 1] &&  a->st[1] == a->sortd[0]))
			ops += sa_print(sts);
		else if (b->st[0] < b->st[1] && !(b->st[0] == b->sortd[b->size - 1] &&  b->st[1] == b->sortd[0]))
			ops += sb_print(sts);
		ops += rr_print(sts);
	}
	return (ops);
}

int	swap_sort(t_stacks **sts)
{
	int	ops;

	ops = 0;
	ops += pushb_smaller_half(sts);
	ft_printf("pushb done!\n");
	// ops += swap_sort_single(sts);
	// ops += swap_sort_rev_single(sts);
	ops += swap_sort_simul(sts);
	ops += bring_max_to_top(sts);
	ops += bring_min_to_top(sts);
	while ((*sts)->b->size)
		ops += pa_print(sts);
	return (ops);
}

