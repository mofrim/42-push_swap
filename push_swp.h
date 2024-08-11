/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:35:30 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 12:29:01 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWP_H
# define PUSH_SWP_H

typedef struct s_stacks
{
	long	*a;
	long	*b;
	int		size;
}	t_stacks;

t_stacks	*init_stacks(int size);
void	fill_stack_rand(t_stacks **st, int size, unsigned int seed);
void	fill_stack_rev(t_stacks **st, int size);
void	free_stacks(t_stacks **st);
void	print_stacks(t_stacks *st);

/* Operations */
void	sa(t_stacks **st);
void	sb(t_stacks **st);
void	ss(t_stacks **st);
void	pa(t_stacks **st);
void	pb(t_stacks **st);
void	ra(t_stacks **st);
void	rb(t_stacks **st);
void	rr(t_stacks **st);
void	rra(t_stacks **st);
void	rrr(t_stacks **st);

#endif 

