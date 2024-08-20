/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:20:49 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 10:21:23 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* rotate a */
int	ra(t_stacks **sts)
{
	long	**a;
	long	tmp;
	int		i;

	a = &((*sts)->a->st);
	i = -1;
	tmp = (*a)[0];
	while (++i < (*sts)->a->size - 1 && (*a)[i + 1] != LONG_MAX)
		(*a)[i] = (*a)[i + 1];
	(*a)[i] = tmp;
	return (1);
}

/* rotate b */
int	rb(t_stacks **sts)
{
	long	**b;
	long	tmp;
	int		i;

	b = &((*sts)->b->st);
	i = -1;
	tmp = (*b)[0];
	while (++i < (*sts)->b->size - 1 && (*b)[i + 1] != LONG_MAX)
		(*b)[i] = (*b)[i + 1];
	(*b)[i] = tmp;
	return (1);
}

/* rotate a & b */
int	rr(t_stacks **sts)
{
	ra(sts);
	rb(sts);
	return (1);
}
