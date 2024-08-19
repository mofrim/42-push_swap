/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:33:41 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 12:08:46 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* The same as strat1_sim, but actually do it. Updates stacks->cur_min.
 * Returns number of ops. */ 
int	strat012_do(t_stacks **sts)
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

int	strat021_do(t_stacks **sts)
{
	int		ops;
	
	ops = 0;
	ops += move_top_min_print(sts, 0);
	ops += pb_print(sts);
	ops += move_top_min_print(sts, 2);
	ops += pb_print(sts);
	ops += move_top_min_print(sts, 1);
	ops += pb_print(sts);
	ops += sb_print(sts);
	(*sts)->cur_min += 3;
	return (ops);
}

int	strat102_do(t_stacks **sts)
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

int	strat120_do(t_stacks **sts)
{
	int		ops;

	ops = 0;
	ops += move_top_min(sts, 1);
	ops += pb(sts);
	ops += move_top_min(sts, 2);
	ops += pb(sts);
	ops += rb(sts);
	ops += move_top_min(sts, 0);
	ops += pb(sts);
	ops += sb(sts);
	ops += rrb(sts);
	(*sts)->cur_min += 3;
	return (ops);
}

int	strat210_do(t_stacks **sts)
{
	int		ops;

	ft_printf("strat3\n");
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
