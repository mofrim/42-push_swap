/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:35:34 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 08:50:57 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* Return the index of maximal elem in stack s. */
int	get_indx_of_stack_max(t_stack *s)
{
	int	i;
	int	max;
	int	imax;

	i = 0;
	max = s->st[0];
	imax = 0;
	while (i < s->size)
	{
		if (max < s->st[i])
		{
			max = s->st[i];
			imax = i;
		}
		i++;
	}
	return (imax);
}

/* Return the index of minimal elem in stack s. */
int	get_indx_of_stack_min(t_stack *s)
{
	int	i;
	int	min;
	int	imin;

	i = 0;
	min = s->st[0];
	imin = 0;
	while (i < s->size)
	{
		if (min > s->st[i])
		{
			min = s->st[i];
			imin = i;
		}
		i++;
	}
	return (imin);
}
