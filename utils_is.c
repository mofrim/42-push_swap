/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:51:29 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/30 11:39:30 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Search for possible duplicates of long value n in long array arr. Returns 1
 * if duplicate is found 0 otherwise. */
int	is_dupl(long n, long *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

/* Quickly check if given long array is sorted ascendingly. */
int	is_sorted(long *arr, int size)
{
	int	i;

	if (size == 1)
		return (1);
	i = 0;
	while (++i < size)
		if (arr[i - 1] > arr[i])
			return (0);
	return (1);
}
