/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:46:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 12:22:53 by fmaurer          ###   ########.fr       */
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
	stacks->a = malloc(size * sizeof(long));
	stacks->b = malloc(size * sizeof(long));
	if (!stacks || !stacks->a || !stacks->b)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		stacks->a[i] = LONG_MAX;
		stacks->b[i] = LONG_MAX;
	}
	stacks->size = size;
	return (stacks);
}

void	free_stacks(t_stacks **st)
{
	free((*st)->a);
	free((*st)->b);
	free(*st);
}

void	fill_stack_rand(t_stacks **st, int size, unsigned int seed)
{
	srand(seed);
	while (--size >= 0)
		(*st)->a[size] = (double)rand() / (double)RAND_MAX * 15;
}

void	fill_stack_rev(t_stacks **st, int size)
{
	while (--size >= 0)
		(*st)->a[size] = (*st)->size - size;
}

void	print_stacks(t_stacks *st)
{
	int	i;

	i = -1;
	while (++i < st->size)
	{
		ft_printf("a[%d] = ", i);
		if (st->a[i] == LONG_MAX)
			ft_printf("   ");
		else
			ft_printf("%d  ", st->a[i]);
		ft_printf("b[%d] = ", i);
		if (st->b[i] == LONG_MAX)
			ft_printf(" \n");
		else
			ft_printf("%d\n", st->b[i]);
	}
}
