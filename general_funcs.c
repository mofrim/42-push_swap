/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:46:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 13:18:46 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

t_stacks	*init_stacks(int size)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(size * sizeof(t_stack));
	stacks->b = malloc(size * sizeof(t_stack));
	stacks->a->st = malloc(size * sizeof(long));
	stacks->b->st = malloc(size * sizeof(long));
	if (!stacks || !stacks->a || !stacks->b || !stacks->a->st || !stacks->b->st)
		exit_error_malloc();
	i = -1;
	while (++i < size)
	{
		stacks->a->st[i] = LONG_MAX;
		stacks->b->st[i] = LONG_MAX;
	}
	stacks->a->size = size;
	stacks->b->size = 0;
	stacks->dsts_a = NULL;
	stacks->dsts_b = NULL;
	stacks->targets = NULL;
	stacks->initial_size = size;
	return (stacks);
}

t_stacks	*init_stacks_with_args(long **args, int size)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(size * sizeof(t_stack));
	stacks->b = malloc(size * sizeof(t_stack));
	stacks->a->st = malloc(size * sizeof(long));
	stacks->b->st = malloc(size * sizeof(long));
	if (!stacks || !stacks->a || !stacks->b || !stacks->a->st || !stacks->b->st)
		exit_error_malloc();
	i = -1;
	while (++i < size)
	{
		stacks->a->st[i] = (*args)[i];
		stacks->b->st[i] = LONG_MAX;
	}
	stacks->a->size = size;
	stacks->b->size = 0;
	stacks->dsts_a = NULL;
	stacks->dsts_b = NULL;
	stacks->targets = NULL;
	stacks->initial_size = size;
	free(*args);
	return (stacks);
}

int	is_in(long *arr, int val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == val)
			return (1);
	return (0);
}

/* Fills stacks->a with a random array. Also fills stacks->sortd with the
 * ascendingly ordered array.*/
void	fill_stack_rand(t_stacks **sts, unsigned int seed)
{
	int		size;
	int		i;
	int		val;
	long	**a;

	size = (*sts)->initial_size;
	a = &((*sts)->a->st);
	srand(seed);
	val = (double)rand() / (double)RAND_MAX * size * 2;
	i = size;
	while (--i >= 0)
	{
		while (is_in(*a, val, size))
			val = (double)rand() / (double)RAND_MAX * size * 2;
		(*a)[i] = val;
	}
}

/* Fills stacks->a with a reversely ordered array. Also fills stacks->sortd with
 * the ascendingly ordered array.*/
void	fill_stack_rev(t_stacks **sts)
{
	int	size;

	size = (*sts)->initial_size;
	while (--size >= 0)
		(*sts)->a->st[size] = (*sts)->a->size - size;
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
