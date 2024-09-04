/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_do_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:39:04 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 15:02:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_both(t_stacks **sts, int *dsta, int *dstb);
static void	move_stack_a(t_stacks **sts, int *dsta);
static void	move_stack_b(t_stacks **sts, int *dstb);

/* Do the best move. */
void	do_best_move(t_stacks **sts, int best)
{
	int			dsta;
	int			dstb;
	t_stacks	*s;

	s = *sts;
	dsta = s->dsts_a[best];
	dstb = s->dsts_b[best];
	move_both(sts, &dsta, &dstb);
	move_stack_a(sts, &dsta);
	move_stack_b(sts, &dstb);
	pa_print(sts);
}

/* Helper function for rotating both stacks. */
static void	move_both(t_stacks **sts, int *dsta, int *dstb)
{
	while ((*dsta) * (*dstb) > 0)
	{
		if (*dsta < 0)
			rrr_print(sts);
		else
			rr_print(sts);
		decrement_dst(dsta);
		decrement_dst(dstb);
	}
}

/* Helper function for rotating only stack A. */
static void	move_stack_a(t_stacks **sts, int *dsta)
{
	while (ps_abs(*dsta) > 0)
	{
		if (*dsta > 0)
			*dsta -= ra_print(sts);
		if (*dsta < 0)
			*dsta += rra_print(sts);
	}
}

/* Helper function for rotating only stack B. */
static void	move_stack_b(t_stacks **sts, int *dstb)
{
	while (ps_abs(*dstb) > 0)
	{
		if (*dstb > 0)
			*dstb -= rb_print(sts);
		if (*dstb < 0)
			*dstb += rrb_print(sts);
	}
}
