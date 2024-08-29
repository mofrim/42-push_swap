/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_dsts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:13:51 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 14:32:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
