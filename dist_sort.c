/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:28:56 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 19:32:03 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"
#include <stdlib.h>

/*
 * Here i want to implement the following idea:
 *
 * 		At least stack-a is treated more like an array. That means when i pb
 * 		stuff to stack-b i now do not want to shift up the whole array until we
 * 		have a empty tail of LONG_MAX, rather i would like to set the position
 * 		where that value was to LONG_MAX. all the other function will have to be
 * 		addapted to this new behavior.
 * 		In the beginning for every element the distance from its final position
 * 		in the sorted array is calculated. One first step might be:
 *
 * 			1) ra or rra the whole stacks a couple of times where all the
 * 			distances are minimized, in a simulation !!! when the optimal number
 * 			of ra's or rra's is found this gets executed.
 *
 * 			1*) compare every elem to the next one. if elem > next -> sa -> ra,
 * 			ra. Until we have rotated through the whole array. Calculate
 * 			distances to final sorted before and after.
 */

/* This func should find the optimal rotations of stack-a for minimizing
 * total_dists. */
int	optimize_dists_rot(t_stacks **sts)
{
	int	i;
	int	*dists;
	int	d;
	int	mind;
	int	rots[(*sts)->initial_size];

	dists = get_dists_array((*sts)->a->st, (*sts)->sortd, (*sts)->initial_size);

	d = 0;
	mind = INT_MAX;
	i = -1;
	while(++i < (*sts)->initial_size)
	{
		d = calc_total_dist((*sts)->a->st, (*sts)->sortd, (*sts)->initial_size);
		ft_printf("total_dist = %d\n", d);
		if (d < mind)
		{
			ft_printf("found new min: %d\n", d);
			mind = d;
		}
		rots[i] = d;
		ra(sts);
	}
	free(dists);
	ft_printf("\nnumber of ra's: %d\n", indexof_int(mind, rots));
	return (indexof_int(mind, rots));
}


