/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:31:20 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 12:00:47 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/*
 * move_topa_min, pb, move_topa_min+1, pb, move_topa_min+2. Return number of
 * ops needed.
 *
 * WARN: When i finally **do** this strat, i will have to update cur_min accordingly.
 */
int	strat1_sim(t_stacks *sts)
{
	t_stacks *dup;
	int		ops;

	dup = stacks_dup(sts);
	ops = 0;
	if (!dup)
		return (-1);
	ops += move_top_min(&dup, 0);
	ops += pb(&dup);
	ops += move_top_min(&dup, 1);
	ops += pb(&dup);
	ops += move_top_min(&dup, 2);
	ops += pb(&dup);
	free_stacks(&dup);
	return (ops);
}

int	strat2_sim(t_stacks *sts)
{
	return (0);
}

int	strat3_sim(t_stacks *sts)
{
	return (0);
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

