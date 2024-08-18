/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:04:26 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/16 20:43:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"
#include <stdlib.h>

long	ft_abs(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	calc_total_dist(long *a, long *sortd, int size)
{
	int	i;
	int	total_dist;

	i = -1;
	total_dist = 0;
	while (++i < size)
		total_dist += ft_abs(i - indexof_long(a[i], sortd, size ));
	return (total_dist);
}

int *get_dists_array(long *a, long *sortd, int size)
{
	int	*dists;
	int	i;

	dists = malloc(size * sizeof(int));
	if (!dists)
		return (NULL);
	i = -1;
	while (++i < size)
		dists[i] = i - indexof_long(a[i], sortd, size );
	return (dists);
}

void	print_dists_stack(t_stacks *sts)
{
	int	*dists;
	int	i;

	dists = get_dists_array(sts->a->st, sts->sortd, sts->initial_size);
	if (!dists)
		return ;
	i = -1;
	while (++i < sts->initial_size)
		ft_printf("a[%2d] = %3d, dist = %3d\n", i, sts->a->st[i], dists[i]);
	ft_printf("\ntotal_dist = %d\n", calc_total_dist(sts->a->st, sts->sortd, sts->initial_size));
	free(dists);
}
