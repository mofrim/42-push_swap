/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stratsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:36:44 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 15:30:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swp.h"

/* One advantage certainly is: if using 3 strats is not enough to archieve
 * small enough num of steps, just add one or two more.
 * Maybe i should also have a strategy for 4 or 5. Just to finish earlier with
 * the copying...
 *
 * Check which strategy takes the least ops. Execute the minimal one. If stack_a
 * is eventually reduced to 3 nums, sort them and push back everything from b.
 *
 * NOTE: it might also be more efficient f.ex. to move_top_min & pb and after that
 * do a strat2 or 3 combo...how to adress that? we could call these 'strat12'
 * and 'strat13'
 *
 * FIXME: handle cases where stack_a is already sorted and we end up with less
 * then 3 elements in stack_a.
 */
int	stratsort(t_stacks **sts)
{
	int	sim_res;
	int	ops;

	ops = 0;
	if ((*sts)->initial_size == 1)
		return (0);
	if ((*sts)->initial_size == 2)
		return (sort2(sts));
	if ((*sts)->initial_size == 3)
		return (sort3(sts));
	while ((*sts)->a->size > 3)
	{
		sim_res = simulate_strats(sts);
		if (sim_res == 1)
			ops += strat1_do(sts);
		if (sim_res == 2)
			ops += strat2_do(sts);
		if (sim_res == 3)
			ops += strat3_do(sts);
	}
	if ((*sts)->a->size == 3)
		ops += sort3(sts);
	if ((*sts)->a->size == 2)
		ops += sort2(sts);
	while ((*sts)->b->size > 0)
		ops += pa_print(sts);
	return (ops);
}

/*
 * Call the simulation functions for all 3 strats and return the strat num which
 * took the least ops.
 */
int	simulate_strats(t_stacks **sts)
{
	int s31;
	int s32;
	int s33;

	s31 = strat31_sim(*sts);
	s32 = strat32_sim(*sts);
	s33 = strat33_sim(*sts);

	if (s31 <= s32 && s31 <= s33)
		return (1);
	if (s32 <= s31 && s32 <= s33)
		return (2);
	if (s33 <= s31 && s33 <=s32)
		return (3);
	return (0);
}

/* Handles 2-elem stack_a. */
int	sort2(t_stacks **sts)
{
	int	ops;

	ops = 0;
	if ((*sts)->a->st[0] > (*sts)->a->st[1])
		ops += sa_print(sts);
	return (ops);
}

/* Handles 3-elem stack_a. */
int	sort3(t_stacks **sts)
{
	long	*a;
	int		ops;

	ops = 0;
	a = (*sts)->a->st;
	if (a[0] > a[1] && a[0] > a[2])
	{
		ops += ra_print(sts);
		if (a[0] > a[1])
			ops += sa_print(sts);
	}
	if (a[1] > a[0] && a[1] > a[2])
	{
		ops += rra_print(sts);
		if (a[0] > a[1])
			ops += sa_print(sts);
	}
	if (a[2] > a[0] && a[2] > a[1])
	{
		if (a[0] > a[1])
			ops += sa_print(sts);
	}
	return (ops);
}
