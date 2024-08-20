/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:18:45 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 10:19:28 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* swap a. Returns 0 if nothing was done. Returns 1 otherwise. */
int	sa(t_stacks **sts)
{
	long	**a;
	long	tmp;

	a = &((*sts)->a->st);
	if ((*a)[0] == LONG_MAX || (*a)[1] == LONG_MAX)
		return (0);
	tmp = (*a)[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = tmp;
	return (1);
}

/* swap b */
int	sb(t_stacks **sts)
{
	long	tmp;
	long	**b;

	b = &((*sts)->b->st);
	if ((*b)[0] == LONG_MAX || (*b)[1] == LONG_MAX)
		return (0);
	tmp = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = tmp;
	return (1);
}

int	ss(t_stacks **sts)
{
	sa(sts);
	sb(sts);
	return (1);
}
