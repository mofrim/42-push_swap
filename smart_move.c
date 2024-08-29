/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:52:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 09:01:54 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decrement_dst(int *dst)
{
	if (*dst > 0)
		(*dst)--;
	if (*dst < 0)
		(*dst)++;
	return (1);
}

int	get_move_ops(int dsta, int dstb)
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

int	do_best_move(t_stacks **sts, int best)
{
	int	dsta;
	int	dstb;
	int	ops;
	t_stacks *s;

	s = *sts;
	dsta = s->dsts_a[best];
	dstb = s->dsts_b[best];
	ops = 0;
	while (dsta * dstb > 0)
	{
		if (dsta < 0)
			ops += rrr_print(sts);
		else
			ops += rr_print(sts);
		decrement_dst(&dsta);
		decrement_dst(&dstb);
	}
	while (ps_abs(dsta) > 0)
	{
		if (dsta > 0)
		{
			ops += ra_print(sts);
			dsta--;
		}
		if (dsta < 0)
		{
			ops += rra_print(sts);
			dsta++;
		}
	}
	while (ps_abs(dstb) > 0)
	{
		if (dstb > 0)
		{
			ops += rb_print(sts);
			dstb--;
		}
		if (dstb < 0)
		{
			ops += rrb_print(sts);
			dstb++;
		}
	}
	ops += pa_print(sts);
	return (ops);
}
