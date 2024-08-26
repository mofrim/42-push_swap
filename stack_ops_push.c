/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:39:55 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/26 06:55:14 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

static void	shift_down_target_stack(t_stack **stck, long tmpa);

static void	shift_up_source_stack(t_stack **stck);

int	pa(t_stacks **sts)
{
	t_stack	*a;
	t_stack	*b;
	long	tmp;

	a = (*sts)->a;
	b = (*sts)->b;
	if (b->st[0] == LONG_MAX)
		return (0);
	tmp = a->st[0];
	a->st[0] = b->st[0];
	shift_down_target_stack(&(*sts)->a, tmp);
	shift_up_source_stack(&(*sts)->b);
	a->size++;
	b->size--;
	return (1);
}

int	pb(t_stacks **sts)
{
	t_stack	*b;
	t_stack	*a;
	long	tmp;

	b = (*sts)->b;
	a = (*sts)->a;
	if (a->st[0] == LONG_MAX)
		return (0);
	tmp = b->st[0];
	b->st[0] = a->st[0];
	shift_down_target_stack(&(*sts)->b, tmp);
	shift_up_source_stack(&(*sts)->a);
	a->size--;
	b->size++;
	return (1);
}

static void	shift_down_target_stack(t_stack **stck, long tmp)
{
	t_stack	*s;
	long	tmpa;
	long	tmpb;
	int		i;

	s = *stck;
	tmpa = tmp;
	i = 0;
	while (++i < s->size || tmpa != LONG_MAX)
	{
		tmpb = s->st[i];
		s->st[i] = tmpa;
		tmpa = tmpb;
	}
}

static void	shift_up_source_stack(t_stack **stck)
{
	t_stack	*s;
	int		i;

	s = *stck;
	i = 0;
	while (i < s->size - 1)
	{
		s->st[i] = s->st[i + 1];
		i++;
	}
	s->st[i] = LONG_MAX;
}
