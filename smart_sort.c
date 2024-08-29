/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:17 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 09:01:55 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stacks **sts);

static void	sort_three(t_stacks **sts);

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
void	smartsort(t_stacks **sts)
{
	int best;

	if ((*sts)->a->size == 1)
		return ;
	if ((*sts)->a->size == 2)
	{
		sort_two(sts);
		return ;
	}
	if ((*sts)->a->size < 200)
		pb_all_but_three_small(sts);
	else
		pb_all_but_three_big(sts);
	sort_three(sts);
	while ((*sts)->b->size)
	{
		calc_dsts(sts);
		best = find_best_move(sts);
		do_best_move(sts, best);
	}
	move_top_min_smart(sts);
}

/* Handles 3-elem stack_a. */
static void	sort_three(t_stacks **sts)
{
	long	*a;

	a = (*sts)->a->st;
	if (a[0] > a[1] && a[0] > a[2])
	{
		ra_print(sts);
		if (a[0] > a[1])
			sa_print(sts);
	}
	if (a[1] > a[0] && a[1] > a[2])
	{
		rra_print(sts);
		if (a[0] > a[1])
			sa_print(sts);
	}
	if (a[2] > a[0] && a[2] > a[1])
		if (a[0] > a[1])
			sa_print(sts);
}


static void	sort_two(t_stacks **sts)
{
	t_stack	*a;

	a = (*sts)->a;
	if (a->st[0] > a->st[1])
		sa_print(sts);
}
