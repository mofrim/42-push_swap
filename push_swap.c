/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/21 08:48:53 by fmaurer          ###   ########.fr       */
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
	long	new;
	int		i;

	st = malloc(sizeof(long) * size);
	i = 0;
	while (i < size)
	{
		new = ps_atol(av[i + 1]);
		if (new == LONG_MAX || is_dupl(new, st, i))
			exit_error_arg();
		st[i] = new;
		i++;
	}
	return (st);
}

// TODO: another IDEA: SniperSort... consecutive number of already sorted
// values.. somehow identify number of unsorted values. then simulate number of
// moves it would take to sort them and only ra, rra them..
// Another IDEA: just copy over unsorted stuff by using a loop like
//
// 		while (is_sorted(slice of stack so far))
// 			count further down the array
// 			if (value is not sorted && values afterwards are sorted again for
// 			more then one value)
// 				pb
// 			then do smart_sort
// TODO: another IDEA: preprocessing... move_min_top on stack a. then push to b
// only those elem which are not in a sorted order from the top. wort case stack
// a looks like [min, max, ....] then only min and max would remain. you would
// have to keep at least 3 elems in order to do sort_three before... doing
// smart_sort. for lists like [1,2,3,100,4,5,6,7,-1,8,9,...] this should
// optimize performance.
int main(int ac, char **av)
{
	long		*array_a;
	int			list_len;
	t_stacks	*stacks;
	int			ops;
	
	if (ac == 1)
		return (0);
	list_len = ac - 1;
	array_a = get_stack_from_args(av, list_len);
	if (is_sorted(array_a, list_len))
		return (0);
	stacks = init_stacks_with_args(&array_a, list_len);
	ops = smartsort(&stacks);
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
