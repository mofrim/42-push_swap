/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 09:50:05 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"
#include <stdlib.h>

void	easy_tests(void);
void	strattest(void);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// t_stacks	*stacks;
	// long *ss;
	// int	size;

	// size = 5;
	// stacks = init_stacks(size);
	// fill_stack_rev(&stacks);
	// fill_stack_rand(&stacks, 12390);
	// print_stacks(stacks);

	// ss = quicksorted_stack(stacks->a->st, stacks->a->size);
	// move_to_top_next(&stacks, ss, 4, size);
	// simple_sort(&stacks);
	// simple_sort2(&stacks);
	// swap_sort(&stacks);
	// bring_max_to_top(&stacks, 5);
	// sa(&stacks);
	// ra(&stacks);
	// sa(&stacks);
	// ra(&stacks);
	// sa(&stacks);
	// bring_max_to_top(&stacks, 3);
	// ra(&stacks);
	// ft_printf("\nsorted:\n");
	// print_stacks(stacks);
	// free_stacks(&stacks);
	
	strattest();
}

void strattest(void)
{
	t_stacks	*stacks;
	int	size;

	size = 5;
	stacks = init_stacks(size);
	fill_stack_rand(&stacks, 4293);
	print_stacks(stacks);

	ft_printf("\nmove_top_min(1):\n\n");
	int ops = move_top_min(&stacks, 1);
	print_stacks(stacks);
	ft_printf("\nneeded ops: %d\n", ops);

	free_stacks(&stacks);
}

void	easy_tests(void)
{
	t_stacks	*stacks;
	int	size;

	size = 5;
	stacks = init_stacks(size);
	// fill_stack_rand(&stacks, size, 3);
	fill_stack_rev(&stacks);
	print_stacks(stacks);

	ft_printf("\neinmal sa:\n");
	sa(&stacks);
	print_stacks(stacks);

	ft_printf("\nzweimal pb:\n");
	pb(&stacks);
	pb(&stacks);
	print_stacks(stacks);

	ft_printf("\neinmal ra:\n");
	ra(&stacks);
	print_stacks(stacks);

	ft_printf("\neinmal pa:\n");
	pa(&stacks);
	print_stacks(stacks);

	ft_printf("\neinmal ra:\n");
	ra(&stacks);
	print_stacks(stacks);

	ft_printf("\neinmal rra:\n");
	rra(&stacks);
	print_stacks(stacks);

	ft_printf("\neinmal pb:\n");
	pb(&stacks);
	print_stacks(stacks);

	ft_printf("\neinmal rrr:\n");
	rrr(&stacks);
	print_stacks(stacks);

	free_stacks(&stacks);
}
