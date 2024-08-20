/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 13:27:41 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"

// FIXME: remove me again !!!
#include <stdio.h>

void smartsort_test(void);

long	*get_stack_from_args(char **av, int size)
{
	long	*st;
	int		i;

	st = malloc(sizeof(long) * size);
	i = 0;
	while (i < size)
	{
		st[i] = ft_atol(av[i + 1]);
		if (st[i] == LONG_MAX)
			exit_error_arg();
		i++;
	}
	return (st);
}

int main(int ac, char **av)
{
	long		*array_a;
	t_stacks	*stacks;
	int			ops;
	
	if (ac == 1)
		return (0);
	array_a = get_stack_from_args(av, ac - 1);
	stacks = init_stacks_with_args(&array_a, ac - 1);
	ops = smartsort(&stacks);
	ft_printf("ops: %d\n", ops);
	free_stacks(&stacks);
	return (0);
}

void smartsort_test(void)
{
	t_stacks	*stacks;
	int			ops;
	int	size;

	size = 50;
	stacks = init_stacks(size);
	// fill_stack_rand(&stacks, 123);
	ops = smartsort(&stacks);
	ft_printf("ops: %d\n", ops);
	free_stacks(&stacks);
}
