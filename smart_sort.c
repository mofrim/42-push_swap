/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:17 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 18:21:51 by fmaurer          ###   ########.fr       */
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
	// calc_dsts(sts);
	// print_dsts_trgts(*sts);
	// best = find_best_move(sts);
	// ft_printf("best move: %d\n", find_best_move(sts));
	// do_best_move(sts, best);
	// calc_dsts(sts);
	// print_dsts_trgts(*sts);
	// best = find_best_move(sts);
	// ft_printf("best move: %d\n", find_best_move(sts));
	// do_best_move(sts, best);
	// calc_dsts(sts);
	// move_top_min_smart(sts);
	// print_dsts_trgts(*sts);
	while ((*sts)->b->size)
	{
		calc_dsts(sts);
		print_dsts_trgts(*sts);
		best = find_best_move(sts);
		ft_printf("best move: %d\n", find_best_move(sts));
		do_best_move(sts, best);
	}
	move_top_min_smart(sts);
	print_dsts_trgts(*sts);
	return (ops);
}
