/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_revrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:38:37 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 09:01:58 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev rotate a */
int	rra(t_stacks **sts)
{
	long	**a;
	long	tmp;
	int		i;

	a = &((*sts)->a->st);
	i = 0;
	while (i < (*sts)->a->size - 1 && (*a)[i] != LONG_MAX)
		i++;
	if ((*a)[i] == LONG_MAX)
		i--;
	tmp = (*a)[i];
	while (i > 0)
	{
		(*a)[i] = (*a)[i - 1];
		i--;
	}
	(*a)[0] = tmp;
	return (1);
}

/* rev rotate b */
int	rrb(t_stacks **sts)
{
	long	**b;
	long	tmp;
	int		i;

	b = &((*sts)->b->st);
	i = 0;
	while (i < (*sts)->b->size - 1 && (*b)[i] != LONG_MAX)
		i++;
	if ((*b)[i] == LONG_MAX)
		i--;
	tmp = (*b)[i];
	while (i > 0)
	{
		(*b)[i] = (*b)[i - 1];
		i--;
	}
	(*b)[0] = tmp;
	return (1);
}

/* rev rotate a & b */
int	rrr(t_stacks **sts)
{
	rra(sts);
	rrb(sts);
	return (1);
}

/* rev rotate a and print rra. */
int	rra_print(t_stacks **sts)
{
	rra(sts);
	ft_printf("rra\n");
	return (1);
}

/* rev rotate b and print rrb. */
int	rrb_print(t_stacks **sts)
{
	rrb(sts);
	ft_printf("rrb\n");
	return (1);
}
