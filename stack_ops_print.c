/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:39:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 18:24:12 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap A & B. */
int	ss_print(t_stacks **sts)
{
	int	op;

	op = ss(sts);
	if (op)
		ft_printf("ss\n");
	return (op);
}

/* Push A and print pa. */
int	pa_print(t_stacks **sts)
{
	int	op;

	op = pa(sts);
	if (op)
		ft_printf("pa\n");
	return (op);
}

/* Push B and print pb. */
int	pb_print(t_stacks **sts)
{
	int	op;

	op = pb(sts);
	if (op)
		ft_printf("pb\n");
	return (op);
}

/* Rotate A & B and print rr. */
int	rr_print(t_stacks **sts)
{
	ra(sts);
	rb(sts);
	ft_printf("rr\n");
	return (1);
}

/* Rev rotate A & B and print rrr. */
int	rrr_print(t_stacks **sts)
{
	rra(sts);
	rrb(sts);
	ft_printf("rrr\n");
	return (1);
}
