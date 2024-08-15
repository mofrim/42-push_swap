/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:33:41 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 12:33:05 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* The same as srat1_sim, but actually do it. Updates stacks->cur_min.
 * Returns number of ops. */ 
int	strat1_do(t_stacks **sts)
{
	int		ops;
	
	ops = 0;
	ops += move_top_min_print(sts, 0);
	ops += pb_print(sts);
	ops += move_top_min_print(sts, 1);
	ops += pb_print(sts);
	ops += move_top_min_print(sts, 2);
	ops += pb_print(sts);
	(*sts)->cur_min += 3;
	return (ops);
}

int	strat2_do(t_stacks **sts)
{
	return (0);
}

int	strat3_do(t_stacks **sts)
{
	return (0);
}
