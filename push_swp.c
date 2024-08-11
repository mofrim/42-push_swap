/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 18:13:54 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"
#include <stdlib.h>

void	easy_tests(void);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stacks	*stacks;
	int	size;

	// size = 4;
	// stacks = init_stacks(size);
	// fill_stack_rev(&stacks, size);
	// print_stacks(stacks);
	// sa(&stacks);
	// ra(&stacks);
	// ra(&stacks);
	// sa(&stacks);
	// ft_printf("\nsorted:\n");
	// print_stacks(stacks);

	size = 5;

	stacks = init_stacks(size);
	fill_stack_rev(&stacks, size);
	print_stacks(stacks);
	ra(&stacks);
	ra(&stacks);
	sa(&stacks);
	rra(&stacks);
	rra(&stacks);
	ft_printf("\nsorted:\n");
	print_stacks(stacks);
}

void	easy_tests(void)
{
	t_stacks	*stacks;
	int	size;

	size = 5;
	stacks = init_stacks(size);
	// fill_stack_rand(&stacks, size, 3);
	fill_stack_rev(&stacks, size);
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
