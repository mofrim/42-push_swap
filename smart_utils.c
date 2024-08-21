/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:18:41 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/22 00:50:26 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

void	move_top_min_smart(t_stacks **sts)
{
	t_stacks	*s;
	int			min_indx;
	int			min;

	s = *sts;
	min_indx = get_min_indx(s->a);
	min = s->a->st[min_indx];
	while (s->a->st[0] != min)
	{
		if (min_indx < s->a->size - min_indx)
			ra_print(sts);
		else
			rra_print(sts);
	}
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
			ft_printf("            -- b[%2d] = %2d, dsts_a = %+3d, dsts_b = " \
					"%+3d, trgt = %2d\n", i, b->st[i], sts->dsts_a[i], \
					sts->dsts_b[i], sts->targets[i]);
		else if (i < a->size)
			ft_printf("a[%2d] = %3d -- \n", i, a->st[i]);
		i++;
	}
}

/* Print stacks a & b. */
void	print_stacks(t_stacks *sts)
{
	int	i;

	i = -1;
	while (++i < sts->initial_size)
	{
		ft_printf("a[%d] = ", i);
		if (sts->a->st[i] == LONG_MAX)
			ft_printf("   ");
		else
			ft_printf("%d  ", sts->a->st[i]);
		ft_printf("b[%d] = ", i);
		if (sts->b->st[i] == LONG_MAX)
			ft_printf(" \n");
		else
			ft_printf("%d\n", sts->b->st[i]);
	}
}
