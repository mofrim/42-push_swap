/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_do_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:39:04 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 14:39:30 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
