/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:19:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 09:01:56 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Set targets arrays belonging to each stack. First each target array is freed.
 * After that all targets are recalculated.
 */
void	set_targets(t_stacks **sts)
{
	t_stack		*a;
	t_stack		*b;
	t_stacks	*s;
	int			i;

	a = (*sts)->a;
	b = (*sts)->b;
	s = *sts;
	if (s->targets)
		free(s->targets);
	s->targets = malloc(sizeof(int) * b->size);
	if (!s->targets)
		exit_error_malloc();
	i = -1;
	while (++i < b->size)
		s->targets[i] = get_target(b->st[i], a, a->size);
}

/*
 * Get target index in stack a. This is **The Heart** of the sorting logic.
 *
 * The Logic Unravelled: let a_i, a_i+1 in A ...
 *
 * 1) If elem is the new max of A and old max is not located at the highest 
 *    index ATM -> put elem after (max_indx+1) old max.
 * 2) If a_i+1 > elem > a_i, obviously -> elem fits right in between a_i and
 *    a_i+1 above a_i+1
 * 3) If a_i+1 > elem but a_i+1 < a_i, so elem < a_i+1 < a_i. elem has to be
 *    above a_i+1 but the list is rotated in a way that min and max element
 *    meet -> still put it between a_i+1 and a_i
 * 4) If elem would be the new min of A and the list rotated is rotated in a way
 *    that old min is on top, or elem is new max and old max is at the bottom of
 *    the list -> put it on top of the list (index 0).
 *
 * That's it.
 */
int	get_target(long elem, t_stack *s, int size)
{
	int	i;
	int	max_indx;

	i = -1;
	max_indx = get_indx_of_stack_max(s);
	if (elem > s->st[max_indx] && max_indx < size - 1)
		return (max_indx + 1);
	while (++i < size - 1)
		if (elem < s->st[i + 1] && (s->st[i] < elem || s->st[i + 1] < s->st[i]))
			return (i + 1);
	return (0);
}
