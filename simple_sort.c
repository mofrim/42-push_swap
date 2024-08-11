/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:00:25 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 19:26:03 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

// FIXME: so far only here for debugging...
#include "libft/libft.h"

// Push everything to b. than find highest number in b, move to top in b and
// pa. again, again, again. this would be for 4 numbers:
// or.... find lowest number in a, rotate to top, pb, find lowest number in b
// again, rotate to top, pb, until to elems remain in a, if first > than last,
// sa, then pa, pa, pa

int	find_imin(t_stack *s)
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
	// ft_printf("imin = %d\n", imin);
	return (imin);
}

void	simple_sort(t_stacks **sts)
{
	int	i;

	while ((*sts)->a->size > 2)
	{
		i = find_imin((*sts)->a);
		while (i-- > 0)
		{
			ft_printf("ra\n");
			ra(sts);
		}
		ft_printf("pb\n");
		pb(sts);
	}
	ft_printf("sa");
	sa(sts);
	while ((*sts)->b->size)
	{
		ft_printf("\npa");
		pa(sts);
	}
}
