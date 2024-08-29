/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:36:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 09:01:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* copy paste from geeks-for-geeks */

#include "push_swap.h"

// TODO: write my own implementation so that i understand it.

void	swap(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Lomuto partition algorithm. Slower then Hoare. */
int	partition(long **arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = (*arr)[high];
	i = low - 1;
	j = low;
	while (j <= high)
	{
		if ((*arr)[j] < pivot)
		{
			i++;
			swap(&(*arr)[i], &(*arr)[j]);
		}
		j++;
	}
	swap(&(*arr)[i + 1], &(*arr)[high]);
	return (i + 1);
}

void	quicksort(long **arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

long	*quicksorted_stack(long *arr, int size)
{
	long	*sorted_stack;
	int		i;

	sorted_stack = malloc(size * sizeof(long));
	if (!sorted_stack)
		return (NULL);
	i = -1;
	while (++i < size)
		sorted_stack[i] = arr[i];
	quicksort(&sorted_stack, 0, size - 1);
	return (sorted_stack);
}
