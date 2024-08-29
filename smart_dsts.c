/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_dsts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:13:51 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 15:07:02 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculate distance for each elem in stack B to move it to its target postion
 * in stack A. */
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
		if (trgt > s->a->size - trgt)
			dsta = trgt - s->a->size;
		else
			dsta = trgt;
		s->dsts_a[i] = dsta;
		s->dsts_b[i] = dstb;
	}
}

/* Helper function to reset dsts arrays before every new calculation round. This
 * also needs to be done because size of stack b will be one less every round. 
 * */
void	reset_dsts(t_stacks **sts)
{
	t_stack	*b;

	b = (*sts)->b;
	if ((*sts)->dsts_a)
		free((*sts)->dsts_a);
	if ((*sts)->dsts_b)
		free((*sts)->dsts_b);
	(*sts)->dsts_a = malloc(sizeof(int) * b->size);
	(*sts)->dsts_b = malloc(sizeof(int) * b->size);
	if (!(*sts)->dsts_a || !(*sts)->dsts_b)
		exit_error_malloc_free_stacks(sts);
}
