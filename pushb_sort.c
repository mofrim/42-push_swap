/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushb_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 06:29:02 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/12 09:49:03 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swp.h"
#include "libft/libft.h"
#include <stdlib.h>


void	move_to_top_next(t_stacks **sts, long *ss, long	xi, int	stack_size)
{
	int	i;
	int	sorted_index_cur;
	int	stack_index_next;

	sorted_index_cur = get_index_sorted(xi, ss, stack_size);
	if (sorted_index_cur == stack_size - 1)
		stack_index_next = 0;
	else
		stack_index_next = -1;
	i = -1;
	while (++i < stack_size && stack_index_next == -1)
		if ((*sts)->a->st[i] == ss[sorted_index_cur + 1])
			stack_index_next = i;
	if (stack_index_next >= stack_size / 2)
		while (stack_size - i++ >= 0)
		{
			ft_printf("rra\n");
			rra(sts);
		}
	else
		while (i-- >= 0)
		{
			ft_printf("ra\n");
			ra(sts);
		}

}

// ..it takes less operations to just move x_i to top -> pb -> ra until x_i+1
// is at top -> pa, move x_i+1 to top -> pb -> move x_i+2 to top -> and so
// on...
// 
// or
//
// take elem at top, pb, find next in sorted order, move this to top, pa,
void	pushb_sort(t_stacks **sts)
{
	long	*ss;
	int		stack_size;
	int		i;

	stack_size = (*sts)->initial_size;
	ss = quicksorted_stack((*sts)->a->st, (*sts)->a->size);

	int	get_index_sorted(long num, long *sorted_stack, int size);
	free(ss);
}
