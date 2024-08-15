/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stratsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:36:44 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 09:23:41 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/*
 * QUESTION: what was the idea behind passing `indx_cur` again? 
 * ANSWER: `indx_cur` is the index of the current to-be-sorted value from the
 * sorted array. 
 */

void	sort2(t_stacks **sts);
void	sort3(t_stacks **sts);
int		simulate_strats(t_stacks **sts);

/* One advantage certainly is: if using 3 strats is not enough to archieve
 * small enough num of steps, just add one or two more.
 * Maybe i should also have a strategy for 4 or 5. Just to finish earlier with
 * the copying...
 *
 * Check which strategy takes the least ops. Execute the minimal one. If stack_a
 * is eventually reduced to 3 nums, sort them and push back everything from b.
 *
 * NOTE: it might also be more efficient f.ex. to move_top_min & pb and after that
 * do a strat2 or 3 combo...how to adress that? we could call these 'strat12'
 * and 'strat13'
 */
void	stratsort(t_stacks **sts)
{
	int	sim_res;

	if ((*sts)->initial_size == 1)
		return ;
	if ((*sts)->initial_size == 2)
		return (sort2(sts));
	if ((*sts)->initial_size == 3)
		return (sort3(sts));

	// from here on it is clear that there are at least 4 elements in a.
	// we can now start the strats. we need another function which runs all the
	// strats and returns strat number which needed the least ops. so:
	//
	// int sim_res = simulate_strats(sts);
	//
	// if (sim_res == 1)
	// 		strat1_do(sts);
	// 	if (sim_res == 2)
	// 		strat2_do(sts);
	//
	// 		... and so on.
	// 		
	// 	but this we would have to do in a loop until there are only 3
	// 	elements left in a.
	// so lt's do that:

	while ((*sts)->a->size > 3)
	{
		sim_res = simulate_strats(sts);
		if (sim_res == 1)
			strat1_do(sts);
		if (sim_res == 2)
			strat2_do(sts);
		if (sim_res == 3)
			strat3_do(sts);
	}
	sort3(sts);
}

/*
 * Call the simulation functions for all 3 strats and return the strat num which
 * took the least ops.
 */
int	simulate_strats(t_stacks **sts)
{
	int s1;
	int s2;
	int s3;

	s1 = strat1_sim(sts);
	s2 = strat2_sim(sts);
	s3 = strat3_sim(sts);

	if (s1 >= s2 && s1 >= s3)
		return (1);
	if (s2 >= s1 && s2 >= s3)
		return (2);
	if (s3 >= s1 && s3 >=s2)
		return (3);
	return (0);
}

/* Handles 2-elem stack_a. */
void	sort2(t_stacks **sts)
{
	if ((*sts)->a->st[0] > (*sts)->a->st[1])
		sa_print(sts);
}

/* Handles 3-elem stack_a. */
void	sort3(t_stacks **sts)
{
	long	*a;

	a = (*sts)->a->st;
	if (a[0] > a[1] && a[0] > a[2])
	{
		ra_print(sts);
		if (a[0] > a[1])
			sa_print(sts);
	}
	if (a[1] > a[0] && a[1] > a[2])
	{
		rra_print(sts);
		if (a[0] > a[1])
			sa_print(sts);
	}
	if (a[2] > a[0] && a[2] > a[1])
	{
		if (a[0] > a[1])
			sa_print(sts);
	}
}
