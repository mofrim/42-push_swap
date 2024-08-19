/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stratsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:36:44 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 12:12:07 by fmaurer          ###   ########.fr       */
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
			ops += strat012_do(sts);
		if (sim_res == 2)
			ops += strat102_do(sts);
		if (sim_res == 3)
			ops += strat210_do(sts);
		if (sim_res == 4)
			ops += strat021_do(sts);
		if (sim_res == 5)
			ops += strat120_do(sts);
	}
	if ((*sts)->a->size == 3)
		ops += sort3(sts);
	if ((*sts)->a->size == 2)
		ops += sort2(sts);
	while ((*sts)->b->size > 0)
		ops += pa_print(sts);
	return (ops);
}

int	strat_optimized(t_stacks **sts)
{
	t_stacks *dup;
	int	ras;
	int	ops;

	dup = stacks_dup(*sts);
	ras = optimize_dists_rot_inv(&dup);
	ft_printf("ras = %d\n", ras);
	ops = 0;
	while (ras > 0)
	{
		ft_printf("from here!");
		ops += ra_print(sts);
		ras--;
	}
	ops += stratsort(sts);
	return (ops);
}
