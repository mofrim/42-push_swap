/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:34:27 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 16:27:46 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/*
 * okay. we need to push some stuff to b. somehow i also need to make use of the
 * rr and ss functions. one idea is: push one half of a to b. but only push the
 * smaller half, which is only elems smaller than sortd[size/2]. Then we know
 * that the half that remains in a and the other half in b is independent. That
 * means, if we push something on one or the other stack it will not need to go
 * into the stack / below the top of the existing stack.
 *
 * One way to go on from there: sort a in place using the bus_sort style. that
 * is rotate through and collect elems which have to go to a different position
 * but in the same direction by pushing them to b, eventually drop them off at
 * the right position.
 *
 *
 *
 * */

int	pushb_smaller_half(t_stacks **sts)
{
	int		i;
	int		sizehalf;
	long	*a;
	long	*b;
	int		ops;

	a = (*sts)->a->st;
	b = (*sts)->b->st;
	sizehalf = (*sts)->initial_size/2;
	ops = 0;
	i = -1;
	while (++i < (*sts)->initial_size)
	{
		if(a[0] < (*sts)->sortd[sizehalf])
			ops += pb_print(sts);
		else
			ra_print(sts);
		if ((*sts)->b->size >= 2 && (*sts)->a->size >= 2)
			if (a[0] > a[1] && b[0] < b[1])
				ss_print(sts);
	}
	return (ops);
}

/* call me like get_stack_dsts(st, st->size) */
// TODO: definitely merge into one func
// TODO: extract dst calculation
void	set_stacka_dsts(t_stacks **sts, int size)
{
	long *sortd;
	int		dst;
	int	i;

	sortd = quicksorted_stack((*sts)->a->st, size);
	(*sts)->dstA = malloc(size * sizeof(int));
	i = -1;
	while (++i < size)
	{
		dst = i - indexof_long((*sts)->a->st[i], sortd, size);
		if (ft_abs(dst) > size - ft_abs(dst))
			dst = size - ft_abs(dst);
		(*sts)->dstA[i] = dst;
	}
}

// TODO: definitely merge into one func
void	inv_long_arr(long **arr, int size)
{
	int	i;
	long	tmp;

	i = -1;
	while(++i < size/2)
	{
		tmp = (*arr)[i];
		(*arr)[i] = (*arr)[size - 1 - i];
		(*arr)[size - 1 - i] = tmp;
	}
}

// TODO: definitely merge into one func
void	set_stackb_dsts(t_stacks **sts, int size)
{
	long *sortd;
	int		dst;
	int	i;

	sortd = quicksorted_stack((*sts)->b->st, size);
	inv_long_arr(&sortd, size);
	(*sts)->dstB = malloc(size * sizeof(int));
	i = -1;
	while (++i < size)
	{
		dst = i - indexof_long((*sts)->b->st[i], sortd, size);
		if (ft_abs(dst) > size - ft_abs(dst))
			dst = size - ft_abs(dst);
		(*sts)->dstB[i] = dst;
	}
}

void	print_dsts(t_stacks *sts)
{
	int	i;

	i = -1;
	while (++i < sts->a->size)
		ft_printf("a[%2d] = %3d, dst = %3d // b[%2d] = %3d, dst = %3d\n", i, sts->a->st[i], sts->dstB[i], i, sts->b->st[i], sts->dstB[i]);
}
