/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:38:37 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 12:13:24 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swp.h"

/* swap a */
void	sa(t_stacks **st)
{
	long tmp;
	long		**a;

	a = &((*st)->a);
	if ((*a)[0] == LONG_MAX || (*a)[1] == LONG_MAX)
		return ;
	tmp = (*a)[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = tmp;
}

/* swap b */
void	sb(t_stacks **st)
{
	long	tmp;
	long	**b;

	b = &((*st)->b);
	if ((*b)[0] == LONG_MAX || (*b)[1] == LONG_MAX)
		return ;
	tmp = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = tmp;
}

/* swap a & b */
void	ss(t_stacks **st)
{
	sa(st);
	sb(st);
}

/* push a */
void	pa(t_stacks **st)
{
	long	**b;
	long	**a;
	long	tmpA;
	long	tmpB;
	int		i;

	b = &((*st)->b);
	a = &((*st)->a);
	if ((*b)[0] == LONG_MAX)
		return ;
	tmpA = (*a)[0];
	(*a)[0] = (*b)[0];
	i = 0;
	while (++i < (*st)->size || tmpA != LONG_MAX)
	{
		tmpB = (*a)[i];
		(*a)[i] = tmpA;
		tmpA = tmpB;
	}
	i = -1;
	while (++i < (*st)->size - 1 || (*b)[i + 1] == LONG_MAX)
		(*b)[i] = (*b)[i + 1];
	(*b)[i] = LONG_MAX;
}

/* push b */
void	pb(t_stacks **st)
{
	long	**b;
	long	**a;
	long	tmpA;
	long	tmpB;
	int		i;

	b = &((*st)->b);
	a = &((*st)->a);
	if ((*a)[0] == LONG_MAX)
		return ;
	tmpA = (*b)[0];
	(*b)[0] = (*a)[0];
	i = 0;
	while (++i < (*st)->size || tmpA != LONG_MAX)
	{
		tmpB = (*b)[i];
		(*b)[i] = tmpA;
		tmpA = tmpB;
	}
	i = -1;
	while (++i < (*st)->size - 1 || (*a)[i + 1] == LONG_MAX)
		(*a)[i] = (*a)[i + 1];
	(*a)[i] = LONG_MAX;
}

/* rotate a */
void	ra(t_stacks **st)
{
	long	**a;
	long	tmp;
	int		i;

	a = &((*st)->a);

	i = -1;
	tmp = (*a)[0];
	while (++i < (*st)->size - 1 && (*a)[i + 1] != LONG_MAX)
		(*a)[i] = (*a)[i + 1];
	(*a)[i] = tmp;
}

/* rotate b */
void	rb(t_stacks **st)
{
	long	**b;
	long	tmp;
	int		i;

	b = &((*st)->b);

	i = -1;
	tmp = (*b)[0];
	while (++i < (*st)->size - 1 && (*b)[i + 1] != LONG_MAX)
		(*b)[i] = (*b)[i + 1];
	(*b)[i] = tmp;
}

/* rotate a & b */
void	rr(t_stacks **st)
{
	ra(st);
	rb(st);
}

/* rotate a */
void	rra(t_stacks **st)
{
	long	**a;
	long	tmp;
	int		i;

	a = &((*st)->a);

	i = 0;
	while (i < (*st)->size - 1 && (*a)[i] != LONG_MAX)
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
}

/* rotate a */
void	rrb(t_stacks **st)
{
	long	**b;
	long	tmp;
	int		i;

	b = &((*st)->b);

	i = 0;
	while (i < (*st)->size - 1 && (*b)[i] != LONG_MAX)
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
}

void	rrr(t_stacks **st)
{
	rra(st);
	rrb(st);
}
