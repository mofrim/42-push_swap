/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:46:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 18:54:22 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>


t_stacks	*init_stacks(int size)
{
	t_stacks	*stacks;
	int		i;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(size * sizeof(t_stack));
	stacks->b = malloc(size * sizeof(t_stack));
	stacks->a->st = malloc(size * sizeof(long));
	stacks->b->st = malloc(size * sizeof(long));
	if (!stacks || !stacks->a || !stacks->b || !stacks->a->st || !stacks->b->st)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		stacks->a->st[i] = LONG_MAX;
		stacks->b->st[i] = LONG_MAX;
	}
	stacks->a->size = size;
	stacks->b->size = 0;
	stacks->initial_size = size;
	return (stacks);
}

void	free_stacks(t_stacks **st)
{
	free((*st)->a->st);
	free((*st)->b->st);
	free((*st)->a);
	free((*st)->b);
	free(*st);
}

void	fill_stack_rand(t_stacks **st, unsigned int seed)
{
	int	size;

	size = (*st)->initial_size;
	srand(seed);
	while (--size >= 0)
		(*st)->a->st[size] = (double)rand() / (double)RAND_MAX * 15;
}

void	fill_stack_rev(t_stacks **st)
{
	int	size;

	size = (*st)->initial_size;
	while (--size >= 0)
		(*st)->a->st[size] = (*st)->a->size - size;
}

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
