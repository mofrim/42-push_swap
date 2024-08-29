/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:18:45 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 18:19:44 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap A. Returns 0 if nothing was done. Returns 1 otherwise. */
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

/* Swap B. */
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

/* Swap A & B. */
int	ss(t_stacks **sts)
{
	int	ops;

	ops = 0;
	ops += sa(sts);
	ops += sb(sts);
	if (ops > 0)
		return (1);
	return (0);
}

/* Swap A, and print that. */
int	sa_print(t_stacks **sts)
{
	int	op;

	op = sa(sts);
	if (op)
		ft_printf("sa\n");
	return (op);
}

/* Swap B, and print that. */
int	sb_print(t_stacks **sts)
{
	int	op;

	op = sb(sts);
	if (op)
		ft_printf("sb\n");
	return (op);
}
