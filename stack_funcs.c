/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:46:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/22 00:46:01 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

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
	return (stacks);
}

void	free_stacks(t_stacks **st)
{
	free((*st)->a->st);
	free((*st)->b->st);
	free((*st)->a);
	free((*st)->b);
	if ((*st)->dsts_b)
		free((*st)->dsts_b);
	if ((*st)->dsts_a)
		free((*st)->dsts_a);
	if ((*st)->targets)
		free((*st)->targets);
	free(*st);
}
