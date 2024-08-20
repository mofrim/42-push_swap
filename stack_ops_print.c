/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_print1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:39:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 10:37:36 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* swap a & b. */
int	ss_print(t_stacks **sts)
{
	ss(sts);
	ft_printf("ss\n");
	return (1);
}

/* push a and print pa. */
int	pa_print(t_stacks **sts)
{
	pa(sts);
	ft_printf("pa\n");
	return (1);
}

/* push b and print pb. */
int	pb_print(t_stacks **sts)
{
	pb(sts);
	ft_printf("pb\n");
	return (1);
}

/* rotate a & b and print rr. */
int	rr_print(t_stacks **sts)
{
	ra(sts);
	rb(sts);
	ft_printf("rr\n");
	return (1);
}

/* rev rotate a & b and print rrr. */
int	rrr_print(t_stacks **sts)
{
	rra(sts);
	rrb(sts);
	ft_printf("rrr\n");
	return (1);
}
