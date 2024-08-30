/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/30 11:14:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	*get_stack_from_args(char **av, int size);

int	main(int ac, char **av)
{
	long		*array_a;
	int			list_len;
	t_stacks	*stacks;

	if (ac == 1)
		return (0);
	list_len = ac - 1;
	array_a = get_stack_from_args(av, list_len);
	if (is_sorted(array_a, list_len))
	{
		free(array_a);
		return (0);
	}
	stacks = init_stacks_with_args(&array_a, list_len);
	free(array_a);
	if (!stacks)
		exit_error_malloc_free_stacks(&stacks);
	smartsort(&stacks);
	free_stacks(&stacks);
	return (0);
}

/* Read stack A from cmdline args. Perform error checking: no int overflow
 * allowed, no duplicates and of course nothing but number. */
static long	*get_stack_from_args(char **av, int size)
{
	long	*st;
	long	new;
	int		i;

	st = malloc(sizeof(long) * size);
	if (!st)
		exit_error_malloc();
	i = 0;
	while (i < size)
	{
		new = ps_atol(av[i + 1]);
		if (new == LONG_MAX || is_dupl(new, st, i))
		{
			free(st);
			exit_error_arg();
		}
		st[i] = new;
		i++;
	}
	return (st);
}
