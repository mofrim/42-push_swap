/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 12:55:47 by fmaurer          ###   ########.fr       */
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
	
	strattest();
}

void strattest(void)
{
	t_stacks	*stacks;
	int	size;

	size = 100;
	stacks = init_stacks(size);
	fill_stack_rand(&stacks, 123);
	print_stacks(stacks);

	ft_printf("\nstrat1_sim1:\n\n");
	// int ops = strat1_do(&stacks);
	int ops = stratsort(&stacks);
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
