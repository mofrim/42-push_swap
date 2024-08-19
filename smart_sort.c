/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:17 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 00:13:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/*
 * smart sort. first pb all but 3 elems. sort those 3 elems. compute dst for
 * every elem in b. let b_0 an elem in b. if b_0 > max_elem_of_a, append to
 * bottom by pa, ra => dst 2.
 *
 * if the next elem in b, b_1 > b_0 this would be rb,pa,ra => dst 3;
 * and so on.
 *
 * but now. if there are some elems in a, say a_x and a_y such that a_x < b_0 <
 * a_y, we need to place b_0 above a_y. this can be done by ra'ing or rra'ing
 * a_y to top of a then pa.
 *
 */
int	smartsort(t_stacks **sts)
{
	int	ops;
	int best;

	ops = 0;
	ops += pb_all_but_three(sts);
	ops += sort_three(sts);
	while ((*sts)->b->size)
	{
		calc_dsts(sts);
		best = find_best_move(sts);
		ops += do_best_move(sts, best);
	}
	ops += move_top_min_smart(sts);
	return (ops);
}
