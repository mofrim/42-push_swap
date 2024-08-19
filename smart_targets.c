/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:19:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 18:49:00 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/*
 * Set targets arrays belonging to each stack. First each target array is freed.
 * After that all targets are recalculated.
 */
void	set_targets(t_stacks **sts)
{
	t_stack		*a;
	t_stack		*b;
	t_stacks	*s;
	int		i;

	a = (*sts)->a;
	b = (*sts)->b;
	s = *sts;
	if (s->targets)
		free(s->targets);
	s->targets = malloc(sizeof(int) * b->size);
	if (!s->targets)
	{
		ft_printf("malloc error!\n");
		exit(ENOMEM);
	}
	i = -1;
	while (++i < b->size)
	{
		s->targets[i] = get_target(b->st[i], a->st, a->size);
		// ft_printf("s->targets[i] = %d\n", s->targets[i]);

	}
}

/* Get target index in stack a. */
int	get_target(long elem, long *st, int size)
{
	int	i;
	int	target;

	i = -1;
	target = -1;
	while (++i < size)
	{
		if (i == 0)
			if (st[0] > elem && elem < st[size - 1])
				return (0);
		if (i == size - 1)
		{
			if (st[size - 1] < elem)
				return (0);
			else
				return (size - 1);
		}
		if (st[i] < elem && elem < st[i + 1])
			return (i + 1);
	}
	return (0);
}
