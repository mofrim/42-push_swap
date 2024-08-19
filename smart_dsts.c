/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_dsts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:13:51 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 18:59:59 by fmaurer          ###   ########.fr       */
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
		if (trgt == -1)
			dsta = INT_MAX;
		else if (trgt > s->a->size - trgt)
			dsta = trgt - s->a->size;
		else
			dsta = trgt;
		s->dstA[i] = dsta;
		s->dstB[i] = dstb;
	}
}

void	reset_dsts(t_stacks **sts)
{
	t_stack *b;
	int		i;

	b = (*sts)->b;
	if ((*sts)->dstA)
		free((*sts)->dstA);
	if ((*sts)->dstB)
		free((*sts)->dstB);
	(*sts)->dstA = malloc(sizeof(int) * b->size);
	(*sts)->dstB = malloc(sizeof(int) * b->size);
	if (!(*sts)->dstA || !(*sts)->dstB)
	{
		ft_printf("malloc error!\n");
		exit(ENOMEM);
	}
	// FIXME: remove that again in the future. maybe
	i = -1;
	while (++i < b->size)
	{
		(*sts)->dstA[i] = 0;
		(*sts)->dstB[i] = 0;
	}
}

