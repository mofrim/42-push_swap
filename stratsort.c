/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stratsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:36:44 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/13 21:40:16 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* I need a stacks_dup function to temporarily duplicate the stacks struct for
 * simulation. Also i want to have the sorted stack inside the stacks struct. */
int	strat1_sim(t_stacks **sts, long **sortd, int indx_cur);
int	strat2_sim(t_stacks **sts, long **sortd, int indx_cur);
int	strat3_sim(t_stacks **sts, long **sortd, int indx_cur);

int	strat1_do(t_stacks **sts, long **sortd, int indx_cur);
int	strat2_do(t_stacks **sts, long **sortd, int indx_cur);
int	strat3_do(t_stacks **sts, long **sortd, int indx_cur);

/* One advantage certainly is: if using 3 strats is not enough to archieve
 * small enough num of steps, just add one or two more. */

/* Maybe i should also have a strategy for 4 or 5. Just to finish earlier with
 * the copying. */

void	stratsort(t_stacks **sts)
{
}
