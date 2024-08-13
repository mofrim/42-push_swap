/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_print1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:39:59 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/13 22:02:28 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swp.h"

/* swap a, and print that. */
void	sa_print(t_stacks **sts)
{
	sa(sts);
	ft_printf("sa\n");
}

/* swap b, and print that. */
void	sb_print(t_stacks **sts)
{
	sb(sts);
	ft_printf("sb\n");
}

/* swap a & b and print ss.
 * QUESTION: maybe this is not exactly the wanted beahvior. Maybe it should only
 * print sa or sb in cases where this was only done.
 */
void	ss_print(t_stacks **sts)
{
	ss(sts);
	ft_printf("ss\n");
}

/* push a and print pa. */
void	pa_print(t_stacks **sts)
{
	pa(sts);
	ft_printf("pa\n");
}

/* push b and print pb. */
void	pb_print(t_stacks **sts)
{
	pb(sts);
	ft_printf("pb\n");
}

/* rotate a and print ra. */
void	ra_print(t_stacks **sts)
{
	ra(sts);
	ft_printf("ra\n");
}

/* rotate b and print rb. */
void	rb_print(t_stacks **sts)
{
	rb(sts);
	ft_printf("rb\n");
}

/* rotate a & b and print rr. */
void	rr_print(t_stacks **sts)
{
	ra(sts);
	rb(sts);
	ft_printf("rr\n");
}

/* rev rotate a and print rra. */
void	rra_print(t_stacks **sts)
{
	rra(sts);
	ft_printf("rra\n");
}

/* rev rotate b and print rrb. */
void	rrb_print(t_stacks **sts)
{
	rrb(sts);
	ft_printf("rrb\n");
}

/* rev rotate a & b and print rrr. */
void	rrr_print(t_stacks **sts)
{
	rra(sts);
	rrb(sts);
	ft_printf("rrr\n");
}
