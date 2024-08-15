/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:31:20 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 15:24:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include <limits.h>

/*
 * move_topa_min, pb, move_topa_min+1, pb, move_topa_min+2. Return number of
 * ops needed.
 *
 * WARN: When i finally **do** this strat, i will have to update cur_min accordingly.
 */
int	strat31_sim(t_stacks *sts)
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

int	strat112_sim(t_stacks *sts)
{
	t_stacks *dup;
	int		ops;

	dup = stacks_dup(sts);
	ops = 0;
	if (!dup)
		return (-1);
	ops += move_top_min(&dup, 0);
	ops += pb(&dup);
	dup->cur_min++;
	ops += move_top_min(&dup, 1);
	ops += pb(&dup);
	ops += move_top_min(&dup, 2);
	ops += pb(&dup);
	free_stacks(&dup);
	return (ops);
}

int	strat32_sim(t_stacks *sts)
{
	t_stacks *dup;
	int		ops;

	dup = stacks_dup(sts);
	ops = 0;
	if (!dup)
		return (-1);
	ops += move_top_min(&dup, 1);
	ops += pb(&dup);
	ops += move_top_min(&dup, 0);
	ops += pb(&dup);
	ops += sb(&dup);
	ops += move_top_min(&dup, 2);
	ops += pb(&dup);
	free_stacks(&dup);
	return (ops);
}

int	strat33_sim(t_stacks *sts)
{
	t_stacks *dup;
	int		ops;

	dup = stacks_dup(sts);
	ops = 0;
	if (!dup)
		return (-1);
	ops += move_top_min(&dup, 2);
	ops += pb(&dup);
	ops += move_top_min(&dup, 1);
	ops += pb(&dup);
	ops += sb(&dup);
	ops += rb(&dup);
	ops += move_top_min(&dup, 0);
	ops += pb(&dup);
	ops += sb(&dup);
	ops += rrb(&dup);
	free_stacks(&dup);
	return (ops);
}

