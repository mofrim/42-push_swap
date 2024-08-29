/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:52:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 15:09:54 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculate number of stack ops needed to move a given elem in stack B to its
 * target pos given the precalculated distances. */
static int	get_move_ops(int dsta, int dstb)
{
	int	ops;

	ops = 0;
	while (dsta * dstb > 0)
	{
		ops += decrement_dst(&dsta);
		decrement_dst(&dstb);
	}
	while (ps_abs(dsta) > 0)
		ops += decrement_dst(&dsta);
	while (ps_abs(dstb) > 0)
		ops += decrement_dst(&dstb);
	return (ops);
}

/* Find the best move to be made given the current stacks-setting. */
int	find_best_move(t_stacks **sts)
{
	int			best;
	int			ops;
	int			min_ops;
	int			i;

	min_ops = INT_MAX;
	best = INT_MAX;
	i = -1;
	while (++i < (*sts)->b->size)
	{
		ops = get_move_ops((*sts)->dsts_a[i], (*sts)->dsts_b[i]);
		if (ops < min_ops)
		{
			min_ops = ops;
			best = i;
		}
	}
	return (best);
}
