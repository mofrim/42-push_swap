/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:38:37 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 11:58:26 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swp.h"

/* TODO: for every operation create a version f.ex. sa_print which also prints
 * "sa", so the versions without print can be used inside the simulation
 * functions and the ones with print in the "do" funcs.
 */

/* swap a. Returns 0 if nothing was done. Returns 1 otherwise. */
int	sa(t_stacks **sts)
{
	long tmp;
	long		**a;

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

/* swap a & b. Returns 0 if neither sa nor sb did anything, 1 if only sa
 * succeeded, 2 if only sb, and 3 if both succeeded. */
int	ss(t_stacks **sts)
{
	int	ret;

	ret = 0;
	ret += sa(sts);
	ret += 2 * sb(sts);
	return (ret);
}

/* push a */
int	pa(t_stacks **sts)
{
	long	**b;
	long	**a;
	long	tmpA;
	long	tmpB;
	int		i;

	b = &((*sts)->b->st);
	a = &((*sts)->a->st);
	if ((*b)[0] == LONG_MAX)
		return (0);
	tmpA = (*a)[0];
	(*a)[0] = (*b)[0];
	i = 0;
	while (++i < (*sts)->a->size || tmpA != LONG_MAX)
	{
		tmpB = (*a)[i];
		(*a)[i] = tmpA;
		tmpA = tmpB;
	}
	i = -1;
	while (++i < (*sts)->b->size - 1 || (*b)[i + 1] == LONG_MAX)
		(*b)[i] = (*b)[i + 1];
	(*b)[i] = LONG_MAX;
	(*sts)->a->size++;
	(*sts)->b->size--;
	return (1);
}

/* push b */
int	pb(t_stacks **sts)
{
	long	**b;
	long	**a;
	long	tmpA;
	long	tmpB;
	int		i;

	b = &((*sts)->b->st);
	a = &((*sts)->a->st);
	if ((*a)[0] == LONG_MAX)
		return (0);
	tmpA = (*b)[0];
	(*b)[0] = (*a)[0];
	i = 0;
	while (++i < (*sts)->b->size || tmpA != LONG_MAX)
	{
		tmpB = (*b)[i];
		(*b)[i] = tmpA;
		tmpA = tmpB;
	}
	i = -1;
	while (++i < (*sts)->a->size - 1 || (*a)[i + 1] == LONG_MAX)
		(*a)[i] = (*a)[i + 1];
	(*a)[i] = LONG_MAX;
	(*sts)->a->size--;
	(*sts)->b->size++;
	return (1);
}

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

/* rotate a */
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

/* rotate b */
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

int	rrr(t_stacks **sts)
{
	rra(sts);
	rrb(sts);
	return (1);
}
