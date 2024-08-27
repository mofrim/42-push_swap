/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:19:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/27 22:22:28 by fmaurer          ###   ########.fr       */
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
	int			i;

	a = (*sts)->a;
	b = (*sts)->b;
	s = *sts;
	if (s->targets)
		free(s->targets);
	s->targets = malloc(sizeof(int) * b->size);
	if (!s->targets)
		exit_error_malloc();
	i = -1;
	while (++i < b->size)
		s->targets[i] = get_target(b->st[i], a, a->size);
}

/* Get target index in stack a. This is the heart of the sorting logic. */
int	get_target(long elem, t_stack *s, int size)
{
	int	i;
	int	max_indx;

	i = -1;
	max_indx = get_indx_of_stack_max(s);
	if (elem > s->st[max_indx] && max_indx < size - 1)
		return (max_indx + 1);
	while (++i < size - 1)
	{
		if (s->st[i] < elem && elem < s->st[i + 1])
			return (i + 1);
		if (elem < s->st[i + 1] && s->st[i + 1] < s->st[i])
			return (i + 1);
	}
	return (0);
}
