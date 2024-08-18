/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:17:40 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/18 12:08:56 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"

/* func for updating sortd array in each stack. */
void	update_sortd_both(t_stacks **sts)
{
	if ((*sts)->a->sortd)
		free_ptr((void **)&(*sts)->a->sortd);
	if ((*sts)->b->sortd)
		free_ptr((void **)&(*sts)->b->sortd);
	(*sts)->a->sortd = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
	(*sts)->b->sortd = quicksorted_stack((*sts)->b->st, (*sts)->b->size);
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

/* FUcking fuck! this is unreadable! NEED TO UPDATE SORTD BEFORE RUNNING THIS!!!
 */
void	swap_sort_single(t_stacks **sts)
{
	long	*st;
	int		size;
	long	min;
	long	max;

	st = (*sts)->a->st;
	size = (*sts)->a->size;
	min = (*sts)->a->sortd[0];
	max = (*sts)->a->sortd[size - 1];

	// oh yeah.
	if (size < 4)
		return ;

	while (!is_stack_sorted(&(*sts)->a))
	{
		if (st[0] > st[1] && st[0] != max && st[1] != min)
		{
			sa_print(sts);
			ra_print(sts);
		}
	}
}

void swap_sort_dual(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}

