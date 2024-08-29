/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:18:41 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 17:40:48 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Move the minimum of stack A to top. */
void	move_to_top_min(t_stacks **sts)
{
	t_stacks	*s;
	int			min_indx;
	int			min;

	s = *sts;
	min_indx = get_indx_of_stack_min(s->a);
	min = s->a->st[min_indx];
	if (min_indx < s->a->size - min_indx)
		while (s->a->st[0] != min)
			ra_print(sts);
	else
		while (s->a->st[0] != min)
			rra_print(sts);
}

/* Decrement absolute value of arg. Always return 1 for using it in ops
 * counting. */
int	decrement_dst(int *dst)
{
	if (*dst > 0)
		(*dst)--;
	if (*dst < 0)
		(*dst)++;
	return (1);
}

/* Output function for dsts and targets debugging. Just wanted to keep as a
 * sounvenir. You never know... */
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
