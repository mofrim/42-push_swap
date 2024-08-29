/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushb_but_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:33:18 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 09:01:52 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Seems to be optimal for N > 200. */
void	pb_all_but_three_big(t_stacks **sts)
{
	long	*sortd;
	long	pivot;
	int		pushed;

	sortd = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
	pivot = sortd[(*sts)->a->size / 3];
	pushed = 0;
	while ((*sts)->a->size > 3 && pushed < (*sts)->a->size / 3 )
	{
		if ((*sts)->a->st[0] <= pivot)
			pushed += pb_print(sts);
		else
			ra_print(sts);
	}
	pivot = sortd[2 * (*sts)->a->size / 3];
	while ((*sts)->a->size > 3 && pushed < 2 * (*sts)->a->size / 3 )
	{
		if ((*sts)->a->st[0] <= pivot)
			pushed += pb_print(sts);
		else
			ra_print(sts);
	}
	free(sortd);
	while ((*sts)->a->size > 3)
		pb_print(sts);
}

void	pb_all_but_three_small(t_stacks **sts)
{
	long	*sortd;
	long	pivot;
	int		pushed;

	sortd = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
	pivot = sortd[(*sts)->a->size / 2];
	free(sortd);
	pushed = 0;
	while ((*sts)->a->size > 3 && pushed < (*sts)->a->size / 2 )
	{
		if ((*sts)->a->st[0] <= pivot)
			pushed += pb_print(sts);
		else
			ra_print(sts);
	}
	while ((*sts)->a->size > 3)
		pb_print(sts);
}
