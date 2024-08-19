/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:33:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 00:27:31 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"
#include <stdlib.h>

void smartsort_test(void);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	smartsort_test();
}

void smartsort_test(void)
{
	t_stacks	*stacks;
	int			ops;
	int	size;

	size = 500;
	stacks = init_stacks(size);
	fill_stack_rand(&stacks, 123);
	ops = smartsort(&stacks);
	ft_printf("ops: %d\n", ops);
	free_stacks(&stacks);
}
