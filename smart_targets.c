/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:19:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 20:08:16 by fmaurer          ###   ########.fr       */
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
		s->targets[i] = get_target(b->st[i], a, a->size);
		// ft_printf("s->targets[i] = %d\n", s->targets[i]);

	}
}

/* Get target index in stack a. */
// FIXME: make this very clear and logic!!!
int	get_target(long elem, t_stack *s, int size)
{
	int	i;
	int	target;

	i = -1;
	target = -1;
	// ft_printf("max: %d\n", get_stack_max(s));
	// ft_printf("max_indx: %d\n", get_max_indx(s));
	if (elem > get_stack_max(s) && get_max_indx(s) < size - 1)
		return(get_max_indx(s) + 1);
	while (++i < size)
	{
		if (i < size - 1)
		{
			if (s->st[i] < elem && elem < s->st[i + 1])
				return (i + 1);
			if (s->st[i] > elem && s->st[i + 1] < s->st[i] && elem < s->st[i + 1])
				return (i + 1);
		}
	}
	return (0);
}
