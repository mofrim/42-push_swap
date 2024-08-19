/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:17 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 13:11:07 by fmaurer          ###   ########.fr       */
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

/* The name says it all. */
int	pb_all_but_three(t_stacks **sts)
{
	int	ops;

	ops = 0;
	while ((*sts)->a->size > 3)
		ops += pb_print(sts);
	return (ops);
}

/* Handles 3-elem stack_a. */
int	sort_three(t_stacks **sts)
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
		if (a[0] > a[1])
			ops += sa_print(sts);
	return (ops);
}

int	smartsort(t_stacks **sts)
{
	int	ops;

	ops = 0;
	ops += pb_all_but_three(sts);
	ops += sort_three(sts);

	return (ops);
}
