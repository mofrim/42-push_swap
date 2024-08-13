/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_print1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:39:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/13 21:07:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"
#include "push_swp.h"

/* swap a, and print that. */
void	sa_print(t_stacks **sts)
{
	long		**a;

	a = &((*sts)->a->st);
	if ((*a)[0] == LONG_MAX || (*a)[1] == LONG_MAX)
		return ;
	sa(sts);
	ft_printf("sa\n");
}

/* swap b, and print that. */
void	sb_print(t_stacks **sts)
{
	long	**b;

	b = &((*sts)->b->st);
	if ((*b)[0] == LONG_MAX || (*b)[1] == LONG_MAX)
		return ;
	sb(sts);
	ft_printf("sb\n");
}

/* swap a & b. Prints ss if ss did anything.
 * QUESTION: maybe this is not exactly the wanted beahvior. Maybe it should only
 * print sa or sb in cases where this was only done.
 */
void	ss_print(t_stacks **sts)
{
	int ss_ret;

	ss_ret = ss(sts);
	if (ss_ret == 0)
		return ;
	if (ss_ret == 1)
		ft_printf("ss\n");
	if (ss_ret == 2)
		ft_printf("ss\n");
	if (ss_ret == 3)
		ft_printf("ss\n");
}

/* push a */
void	pa(t_stacks **sts)
{
	long	**b;
	long	**a;
	long	tmpA;
	long	tmpB;
	int		i;

	b = &((*sts)->b->st);
	a = &((*sts)->a->st);
	if ((*b)[0] == LONG_MAX)
		return ;
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
}

/* push b */
void	pb(t_stacks **sts)
{
	long	**b;
	long	**a;
	long	tmpA;
	long	tmpB;
	int		i;

	b = &((*sts)->b->st);
	a = &((*sts)->a->st);
	if ((*a)[0] == LONG_MAX)
		return ;
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
}

/* rotate a */
void	ra(t_stacks **sts)
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
}

/* rotate b */
void	rb(t_stacks **sts)
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
}

/* rotate a & b */
void	rr(t_stacks **sts)
{
	ra(sts);
	rb(sts);
}

/* rotate a */
void	rra(t_stacks **sts)
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
}

/* rotate b */
void	rrb(t_stacks **sts)
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
}

void	rrr(t_stacks **sts)
{
	rra(sts);
	rrb(sts);
}


