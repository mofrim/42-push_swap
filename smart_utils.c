/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:18:41 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/21 20:15:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

long	get_stack_max(t_stack *stck)
{
	int	i;
	int	max;

	max = INT_MIN;
	i = -1;
	while (++i < stck->size)
		if (stck->st[i] > max)
			max = stck->st[i];
	return (max);
}

/* Seems to be optimal for N > 200. */
int	pb_all_but_three_big(t_stacks **sts)
{
	int		ops;
	long	*sortd;
	long	pivot;
	int		pushed;

	sortd = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
	pivot = sortd[(*sts)->a->size / 3];
	ops = 0;
	pushed = 0;
	while ((*sts)->a->size > 3 && pushed < (*sts)->a->size / 3 )
	{
		if ((*sts)->a->st[0] <= pivot)
		{
			ops += pb_print(sts);
			pushed++;
		}
		else
			ops += ra_print(sts);
	}
	pivot = sortd[2 * (*sts)->a->size / 3];
	while ((*sts)->a->size > 3 && pushed < 2 * (*sts)->a->size / 3 )
	{
		if ((*sts)->a->st[0] <= pivot)
		{
			ops += pb_print(sts);
			pushed++;
		}
		else
			ops += ra_print(sts);
	}
	free(sortd);
	while ((*sts)->a->size > 3)
		ops += pb_print(sts);
	return (ops);
}

/* For N <= 200 this seems to be optimal. */
// int	pb_all_but_three(t_stacks **sts)
// {
// 	int		ops;
// 	long	*sortd;
// 	long	pivot;
// 	int		pushed;
//
// 	sortd = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
// 	pivot = sortd[(*sts)->a->size / 2];
// 	free(sortd);
// 	ops = 0;
// 	pushed = 0;
// 	while ((*sts)->a->size > 3 && pushed < (*sts)->a->size / 2 )
// 	{
// 		if ((*sts)->a->st[0] <= pivot)
// 		{
// 			ops += pb_print(sts);
// 			pushed++;
// 		}
// 		else
// 			ops += ra_print(sts);
// 	}
// 	while ((*sts)->a->size > 3)
// 	{
// 		ops += pb_print(sts);
// 	 	if ((*sts)->a->st[0] > (*sts)->a->st[1] &&  (*sts)->b->st[0] <   (*sts)->b->st[1])
//
// 	}
// 	return (ops);
// }

int	pb_all_but_three_small(t_stacks **sts)
{
	int		ops;
	long	*sortd;
	long	pivot;
	int		pushed;

	sortd = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
	pivot = sortd[(*sts)->a->size / 2];
	free(sortd);
	ops = 0;
	pushed = 0;
	while ((*sts)->a->size > 3 && pushed < (*sts)->a->size / 2 )
	{
		if ((*sts)->a->st[0] <= pivot)
		{
			ops += pb_print(sts);
			pushed++;
		}
		else
			ops += ra_print(sts);
	}
	while ((*sts)->a->size > 3)
		ops += pb_print(sts);
	return (ops);
}

/* Handles 3-elem stack_a. */
int	sort_three(t_stacks **sts)
{
	long	*a;
	int		ops;

	ops = 0;
	a = (*sts)->a->st;
	if (a[0] > a[1] && a[0] > a[2])
	{
		ops += ra_print(sts);
		if (a[0] > a[1])
			ops += sa_print(sts);
	}
	if (a[1] > a[0] && a[1] > a[2])
	{
		ops += rra_print(sts);
		if (a[0] > a[1])
			ops += sa_print(sts);
	}
	if (a[2] > a[0] && a[2] > a[1])
		if (a[0] > a[1])
			ops += sa_print(sts);
	return (ops);
}

void	print_dsts_trgts(t_stacks *sts)
{
	int			i;
	t_stack		*a;
	t_stack		*b;

	a = sts->a;
	b = sts->b;
	i = 0;
	while (i < a->size || i < b->size)
	{
		if (i < a->size && i < b->size)
			ft_printf("a[%2d] = %3d -- b[%2d] = %2d, dsts_a = %+3d, " \
					"dsts_b = %+3d, trgt = %2d\n", i, a->st[i], i, b->st[i], \
					sts->dsts_a[i], sts->dsts_b[i], sts->targets[i]);
		else if (i < b->size)
			ft_printf("            -- b[%2d] = %2d, dsts_a = %+3d, dsts_b = %+3d, "\
					"trgt = %2d\n", i, b->st[i], sts->dsts_a[i], sts->dsts_b[i], \
					sts->targets[i]);
		else if (i < a->size)
			ft_printf("a[%2d] = %3d -- \n", i, a->st[i]);
		i++;
	}
}

int	get_min_indx(t_stack *s)
{
	int	i;
	int	min;
	int	imin;

	if (!s->size)
		return (-1);
	i = 0;
	min = s->st[0];
	imin = 0;
	while (i < s->size)
	{
		if (min > s->st[i])
		{
			min = s->st[i];
			imin = i;
		}
		i++;
	}
	return (imin);
}

// FIXME: rename!!
int	move_top_min_smart(t_stacks **sts)
{
	t_stacks	*s;
	int			min_indx;
	int			ops;
	int			min;

	s = *sts;
	min_indx = get_min_indx(s->a);
	min = s->a->st[min_indx];
	ops = 0;
	while (s->a->st[0] != min)
	{
		if (min_indx < s->a->size - min_indx)
			ops += ra_print(sts);
		else
			ops += rra_print(sts);
	}
	return (ops);
}
