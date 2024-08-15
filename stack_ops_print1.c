/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_print1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:39:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/15 12:26:38 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swp.h"

/* swap a, and print that. */
int	sa_print(t_stacks **sts)
{
	sa(sts);
	ft_printf("sa\n");
	return (1);
}

/* swap b, and print that. */
int	sb_print(t_stacks **sts)
{

	sb(sts);
	ft_printf("sb\n");
	return (1);
}

/* swap a & b and print ss.
 * QUESTION: maybe this is not exactly the wanted beahvior. Maybe it should only
 * print sa or sb in cases where this was only done.
 */
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

/* rotate a and print ra. */
int	ra_print(t_stacks **sts)
{
	ra(sts);
	ft_printf("ra\n");
	return (1);
}

/* rotate b and print rb. */
int	rb_print(t_stacks **sts)
{
	rb(sts);
	ft_printf("rb\n");
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

/* rev rotate a and print rra. */
int	rra_print(t_stacks **sts)
{

	rra(sts);
	ft_printf("rra\n");
	return (1);
}

/* rev rotate b and print rrb. */
int	rrb_print(t_stacks **sts)
{
	rrb(sts);
	ft_printf("rrb\n");
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
