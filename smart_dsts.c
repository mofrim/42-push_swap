/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_dsts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:13:51 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/21 12:05:02 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/*
 * All the dsts computation in here please!
 *
 * I also need to specify a target position in a beforehand. So, if b_x goes to
 * to the end that would be INT_MAX. If a_i < b_x < a_i+1 that would be i+1.
 */

void	calc_dsts(t_stacks **sts)
{
	int			dsta;
	int			dstb;
	t_stacks	*s;
	int			trgt;
	int			i;

	reset_dsts(sts);
	set_targets(sts);
	s = *sts;
	i = -1;
	while (++i < s->b->size)
	{
		trgt = s->targets[i];
		if (i > s->b->size - i)
			dstb = i - s->b->size;
		else
			dstb = i;
		// if (trgt == -1)
		// 	dsta = INT_MAX;
		if (trgt > s->a->size - trgt)
			dsta = trgt - s->a->size;
		else
			dsta = trgt;
		s->dsts_a[i] = dsta;
		s->dsts_b[i] = dstb;
	}
}

void	reset_dsts(t_stacks **sts)
{
	t_stack *b;
	int		i;

	b = (*sts)->b;
	if ((*sts)->dsts_a)
		free((*sts)->dsts_a);
	if ((*sts)->dsts_b)
		free((*sts)->dsts_b);
	(*sts)->dsts_a = malloc(sizeof(int) * b->size);
	(*sts)->dsts_b = malloc(sizeof(int) * b->size);
	if (!(*sts)->dsts_a || !(*sts)->dsts_b)
		exit_error_malloc();
	// FIXME: remove that again in the future. maybe
	// i = -1;
	// while (++i < b->size)
	// {
	// 	(*sts)->dsts_a[i] = 0;
	// 	(*sts)->dsts_b[i] = 0;
	// }
}

