/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stratsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:36:44 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/14 20:55:19 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* I need a stacks_dup function to temporarily duplicate the stacks struct for
 * simulation. Also i want to have the sorted stack inside the stacks struct. */
t_stacks	*stacks_dup(t_stacks *sts_orig);

/* QUESTION: what was the idea behind passing `indx_cur` again? 
 * ANSWER: `indx_cur` is the index of the current to-be-sorted value from the
 * sorted array. 
 */

/* 3 funcs to simulate the 3 possibilities:
 *
 * 	1) 	current min (indx_cur in sortd array) is easiest to rotate to top of a
 * 		-> strat1
 * 	2)	min+1, which is the next biggest number (min+2 > min+1 > min !!) is
 * 		fastet to move to top and sb'd, then min has to be moved to top and sb'd
 * 		of a -> strat2
 * 	3)	min+2, which is the next next biggest number is fastet to move to top
 * 	of a, then sb'd, then min+1 to top and sb, then m-> strat2
 *
 * 	Return value of _sim funcs: number of ops they needed to get 
 *
 * 	NOTE: do strats until there are only 3 numbers left in a. this will be the 3
 * 	biggest nums. sort them with sort3. then start pa'ing the stuff back.
 * */

/*
 * move_topa_min, pb, move_topa_min+1, pb, move_topa_min+2. Return number of
 * ops needed.
 */
int	strat1_sim(t_stacks **sts, int indx_cur);

/*
 * move_topa_min+2, pb, move_topa_min, pb, sb.
 */
int	strat2_sim(t_stacks **sts, int indx_cur);
int	strat3_sim(t_stacks **sts, int indx_cur);


/* This should be the strategies  */
int	strat1_do(t_stacks **sts, int indx_cur);
int	strat2_do(t_stacks **sts, int indx_cur);
int	strat3_do(t_stacks **sts, int indx_cur);

/* Simply sort 2 elem array. */
void	sort2(t_stacks **sts);

/* Simply sort 3 elem array. */
void	sort3(t_stacks **sts);

/* One advantage certainly is: if using 3 strats is not enough to archieve
 * small enough num of steps, just add one or two more.
 * Maybe i should also have a strategy for 4 or 5. Just to finish earlier with
 * the copying...
 */

/* Check which strategy takes the least ops. Execute the minimal one. If stack_a
 * is eventually reduced to 3 nums, sort them and push back everything from b.
 *
 * NOTE: it might also be more efficient f.ex. to move_top_min & pb and after that
 * do a strat2 or 3 combo...how to adress that? we could call these 'strat12'
 * and 'strat13'
 */
void	stratsort(t_stacks **sts)
{
	if ((*sts)->initial_size == 1)
		return ;
	if ((*sts)->initial_size == 2)
		return (sort2(sts));
	if ((*sts)->initial_size == 3)
		return (sort3(sts));
}

/* Handles 2-elem stack_a. */
void	sort2(t_stacks **sts)
{
	if ((*sts)->a->st[0] > (*sts)->a->st[1])
		sa_print(sts);
}

/* WARN: free me! */
t_stacks	*stacks_dup(t_stacks *orig)
{
	t_stacks	*dup;
	int			i;

	if (!orig)
		return (NULL);
	dup = init_stacks(orig->initial_size);
	if (!dup)
		return (NULL);

	i = -1;
	while (++i < dup->initial_size)
	{
		dup->a->st[i] = orig->a->st[i];
		dup->b->st[i] = orig->b->st[i];
		dup->sortd[i] = orig->sortd[i];
	}
	dup->a->size = orig->a->size;
	dup->b->size = orig->b->size;
	dup->cur_min = orig->cur_min;
	return (dup);
}
