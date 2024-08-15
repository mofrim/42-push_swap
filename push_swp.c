/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 15:27:56 by fmaurer          ###   ########.fr       */
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
