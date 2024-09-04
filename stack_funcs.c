/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:46:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/30 11:52:44 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_initial_values(t_stacks **sts, int size);

/* Init all components of t_stacks struct. If malloccing goes wrong anywhere
 * return NULL for error handling in main func. */
t_stacks	*init_stacks_with_args(long **args, int size)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = malloc(size * sizeof(t_stack));
	stacks->b = malloc(size * sizeof(t_stack));
	if (!stacks->a || !stacks->b)
		return (NULL);
	stacks->a->st = malloc(size * sizeof(long));
	stacks->b->st = malloc(size * sizeof(long));
	if (!stacks->a->st || !stacks->b->st)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		stacks->a->st[i] = (*args)[i];
		stacks->b->st[i] = LONG_MAX;
	}
	set_initial_values(&stacks, size);
	return (stacks);
}

void	set_initial_values(t_stacks **sts, int size)
{
	(*sts)->a->size = size;
	(*sts)->b->size = 0;
	(*sts)->dsts_a = NULL;
	(*sts)->dsts_b = NULL;
	(*sts)->targets = NULL;
	(*sts)->initial_size = size;
}

/* Conditionally free all components of t_stacks struct. */
void	free_stacks(t_stacks **st)
{
	if ((*st)->a->st)
		free((*st)->a->st);
	if ((*st)->b->st)
		free((*st)->b->st);
	if ((*st)->a)
		free((*st)->a);
	if ((*st)->b)
		free((*st)->b);
	if ((*st)->dsts_b)
		free((*st)->dsts_b);
	if ((*st)->dsts_a)
		free((*st)->dsts_a);
	if ((*st)->targets)
		free((*st)->targets);
	if (*st)
		free(*st);
}

/* Print stacks a & b. Not used, but also wanted to keep as a souvenir. */
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
