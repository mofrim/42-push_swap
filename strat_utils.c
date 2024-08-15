/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:35:26 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/14 23:17:51 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include <stdlib.h>

/* I need a stacks_dup function to temporarily duplicate the stacks struct for
 * simulation. Also i want to have the sorted stack inside the stacks struct. */
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
