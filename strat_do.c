/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:33:41 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 13:57:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* The same as strat1_sim, but actually do it. Updates stacks->cur_min.
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
	int		ops;

	ops = 0;
	ops += move_top_min_print(sts, 1);
	ops += pb(sts);
	ops += move_top_min_print(sts, 0);
	ops += pb(sts);
	ops += sb(sts);
	ops += move_top_min_print(sts, 2);
	ops += pb(sts);
	(*sts)->cur_min += 3;
	return (ops);
}

int	strat3_do(t_stacks **sts)
{
	int		ops;

	ops = 0;
	ops += move_top_min_print(sts, 2);
	ops += pb(sts);
	ops += move_top_min_print(sts, 1);
	ops += pb(sts);
	ops += sb(sts);
	ops += rb(sts);
	ops += move_top_min_print(sts, 0);
	ops += pb(sts);
	ops += sb(sts);
	ops += rrb(sts);
	(*sts)->cur_min += 3;
	return (ops);
}
