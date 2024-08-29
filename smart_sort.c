/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:17 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 17:30:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stacks **sts);
static void	sort_three(t_stacks **sts);

/* The main sorting function.
 * 1) Handle small stack sizes
 * 2) Push all but 3 elems to B (Optimized).
 * 3) Do the sorting using the distance algortihm until stack B is empty again.
 * 4) Finally move the minimal elem in stack A to top. 
 */
void	smartsort(t_stacks **sts)
{
	int	best;

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
	move_to_top_min(sts);
}

/* Sort 3-elem stack A */
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

/* Sort 2-elem stack A */
static void	sort_two(t_stacks **sts)
{
	t_stack	*a;

	a = (*sts)->a;
	if (a->st[0] > a->st[1])
		sa_print(sts);
}
