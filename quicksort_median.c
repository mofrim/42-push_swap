/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:19:02 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 10:26:36 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_pivot(long *arr, int left, int right);
static void	swap(long *a, long *b);
static int	partition_median(long **arr, int left, int right);

static void	quicksort_median(long **arr, int left, int right)
{
	int	part_indx;

	if (left < right)
	{
		part_indx = partition_median(arr, left, right);
		quicksort_median(arr, left, part_indx - 1);
		quicksort_median(arr, part_indx + 1, right);
	}
}

static int	partition_median(long **arr, int left, int right)
{
	int		i;
	int		j;
	long	pivot;

	i = left;
	pivot = get_pivot(*arr, left, right);
	j = right;
	while (1)
	{
		while ((*arr)[j] > pivot)
			j--;
		while ((*arr)[i] < pivot)
			i++;
		if (i < j)
		{
			swap(&(*arr)[i], &(*arr)[j]);
			i++;
			j--;
		}
		else
			return (j + 1);
	}
}

/* Taking the median. */
static long	get_pivot(long *arr, int left, int right)
{
	long	x;
	long	y;
	long	z;

	if (right - left < 2)
	{
		if (arr[left] > arr[right])
			return (arr[right]);
		else
			return (arr[left]);
	}
	x = arr[left];
	y = arr[(right - left) / 2 + left];
	z = arr[right];
	if ((x < y && y < z) || (z < y && y < x))
		return (y);
	if ((y < x && x < z) || (z < x && x < y))
		return (x);
	return (z);
}

static void	swap(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
	quicksort_median(&sorted_stack, 0, size - 1);
	return (sorted_stack);
}
