/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 19:43:13 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"
#include <stdlib.h>

void	easy_tests(void);
void	strattest(void);
void	distsorttest(void);
void strat_optimized_test(void);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	strat_optimized_test();
}


void strat_optimized_test(void)
{
	t_stacks	*stacks;
	t_stacks	*dup;
	int	size;
	int ops1, ops2;

	size = 20;
	stacks = init_stacks(size);
	fill_stack_rand(&stacks, 1);
	dup = stacks_dup(stacks);
	ops1 = stratsort(&stacks);
	ops2 = strat_optimized(&dup);
	ft_printf("normal ops: %d\noptimized ops: %d\n", ops1, ops2);
	free_stacks(&stacks);
	free_stacks(&dup);
}

void distsorttest(void)
{
	t_stacks	*stacks;
	int	size;

	size = 20;
	stacks = init_stacks(size);
	fill_stack_rand(&stacks, 1);
	print_stacks(stacks);
	ft_printf("\ndists:\n\n");
	// print_dists_stack(stacks);
	optimize_dists_rot(&stacks);
	free_stacks(&stacks);
}

void strattest(void)
{
	t_stacks	*stacks;
	int	size;

	size = 100;
	stacks = init_stacks(size);
	fill_stack_rand(&stacks, 1);
	// fill_stack_rev(&stacks);
	print_stacks(stacks);

	ft_printf("\nstratsort:\n\n");
	// int ops = strat1_do(&stacks);
	int ops = stratsort(&stacks);
	print_stacks(stacks);
	ft_printf("\n%d ops\n", ops);

	free_stacks(&stacks);
}
