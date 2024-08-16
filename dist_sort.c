/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:28:56 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/16 06:54:26 by fmaurer          ###   ########.fr       */
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
			// ft_printf("found new min: %d\n", d);
			mind = d;
		}
		rots[i] = d;
		ra(sts);
	}
	free(dists);
	// ft_printf("\nnumber of ra's: %d\n", indexof_int(mind, rots));
	return (indexof_int(mind, rots));
}

int	optimize_dists_rot_inv(t_stacks **sts)
{
	int	i;
	int	*dists;
	int	d;
	int	mind;
	int	rots[(*sts)->initial_size];
	long	*sortd_inv;

	sortd_inv = malloc(sizeof(long) * (*sts)->initial_size);
	i = (*sts)->initial_size;
	while (--i >= 0)
		sortd_inv[(*sts)->initial_size - i - 1] = (*sts)->sortd[i];
	dists = get_dists_array((*sts)->a->st, sortd_inv, (*sts)->initial_size);

	d = 0;
	mind = INT_MAX;
	i = -1;
	while(++i < (*sts)->initial_size)
	{
		d = calc_total_dist((*sts)->a->st, sortd_inv, (*sts)->initial_size);
		ft_printf("total_dist = %d, sortd_inv[i] = %d\n", d, sortd_inv[i]);
		if (d < mind)
		{
			// ft_printf("found new min: %d\n", d);
			mind = d;
		}
		rots[i] = d;
		ra(sts);
	}
	free(dists);
	free(sortd_inv);
	// ft_printf("\nnumber of ra's: %d\n", indexof_int(mind, rots));
	return (indexof_int(mind, rots));
}

/*
 * Implement the idea from above: compare elements and move BIGGER ones above
 * SMALLER ones. THIS IS FOR OPTIMIZING FOR STRATSORT !!! 
 *
 * ok. i give up array approach :(
 *
 */
int	mixed_optimize(t_stacks **sts)
{
	return (0);
}

/* right now i am getting another idea.. what if we pretend the stacks-a are
 * linked together at position 0 from the start. that means. if a[0] has postion
 * 10 in the final array: pb -> 10x ra -> pa. then take the elem above or below
 * in a. pb -> X times ra, pa.*/

/* Oh, a even better idea. I call it
 *
 * 		bus_sort
 *
 * 	The idea: scan for an area where we have elems in stack-a that would
 * need shifting in the same direction. Then, start ra'ing and pb'ing. stack-b
 * 	functions like a bus where the elements wait until it is time to drop
 * them of. in every block, ra or rra to the element with the highest shift
 * needed.
 *
 * until we reach the first position where one of the elems should be
 * dropped of. this would...
 *
 * damn. i slowly get the feeling that working with linked lists here would be
 * much more convenient. with the lists we could save for every list item its
 * position in the final sorted list, its distance from that position, ...*/
