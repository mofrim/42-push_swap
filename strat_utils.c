/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:35:26 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 12:32:52 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include <stdlib.h>

/* I need a stacks_dup function to temporarily duplicate the stacks struct for
 * simulation. Also i want to have the sorted stack inside the stacks struct. */
t_stacks	*stacks_dup(t_stacks *orig)
{
	t_stacks	*dup;
	int			i;

	if (!orig)
		return (NULL);
	dup = init_stacks_empty(orig->initial_size);
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < dup->initial_size)
	{
		dup->a->st[i] = orig->a->st[i];
		dup->b->st[i] = orig->b->st[i];
		dup->sortd[i] = orig->sortd[i];
	}
	dup->a->size = orig->a->size;
	dup->b->size = orig->b->size;
	dup->cur_min = orig->cur_min;
	return (dup);
}

/* Return index of value `num` in array of longs `stack`. */
int	get_stack_index(long num, long *stack)
{
	int	i;

	i = 0;
	while (stack[i] != num)
		i++;
	return (i);
}

/* This function should move the element specified minimal element to top of
 * stack a. The minimal element of interest min, min+1, min+2 will be chosen
 * from the cur_min variable inside t_stacks struct which holds the index of the
 * current minimal value to be handled. For min+1 set min_offset to 1. The
 * corresponding index of this element in stack a will be found by
 * get_stack_index. Return value is the number of moves needed to move value of
 * interest to top of a. */
int move_top_min(t_stacks **sts, int min_offset)
{
	int	indx_a;
	int	indx_min;
	int	ops;

	indx_min = (*sts)->cur_min + min_offset;
	if (indx_min >= (*sts)->initial_size)
		return (-1);
	indx_a = get_stack_index((*sts)->sortd[indx_min], (*sts)->a->st);
	ops = 0;
	while ((*sts)->a->st[0] != (*sts)->sortd[indx_min])
	{
		if (indx_a < (*sts)->a->size - indx_a)
			ops += ra(sts);
		else
			ops += rra(sts);
	}
	return (ops);
}

/* The same func. This one just prints ops along the way. */
int move_top_min_print(t_stacks **sts, int min_offset)
{
	int	indx_a;
	int	indx_min;
	int	ops;

	indx_min = (*sts)->cur_min + min_offset;
	if (indx_min >= (*sts)->initial_size)
		return (-1);
	indx_a = get_stack_index((*sts)->sortd[indx_min], (*sts)->a->st);
	ops = 0;
	while ((*sts)->a->st[0] != (*sts)->sortd[indx_min])
	{
		if (indx_a < (*sts)->a->size - indx_a)
			ops += ra_print(sts);
		else
			ops += rra_print(sts);
	}
	return (ops);
}
