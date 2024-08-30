/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:18:40 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/30 11:41:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(long **arr, int left, int right);
static void	swap(long *a, long *b);

static void	quicksort(long **arr, int left, int right)
{
	int	part_indx;

	if (left < right)
	{
		part_indx = partition(arr, left, right);
		quicksort(arr, left, part_indx - 1);
		quicksort(arr, part_indx + 1, right);
	}
}

/* Kind of my own algorithm. Neither Lomuto, nor Hoare. But it can deal with
 * duplicates \o/ */
static int	partition(long **arr, int left, int right)
{
	int		i;
	int		j;
	long	pivot;

	i = left;
	pivot = (*arr)[right];
	j = right - 1;
	while (i < j)
	{
		while (i < right && (*arr)[i] <= pivot)
			i++;
		while (j > i && (*arr)[j] > pivot)
			j--;
		if (i < j)
			swap(&(*arr)[i], &(*arr)[j]);
	}
	if ((*arr)[i] > pivot)
		swap(&(*arr)[i], &(*arr)[right]);
	else
		i = right;
	return (i);
}

/* Swap two long numbers. */
static void	swap(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Return malloced sorted array of longs. */
long	*get_quicksorted_stack_a(t_stacks **sts, int size)
{
	long	*sorted_stack;
	int		i;

	sorted_stack = malloc(size * sizeof(long));
	if (!sorted_stack)
		exit_error_malloc_free_stacks(sts);
	i = -1;
	while (++i < size)
		sorted_stack[i] = (*sts)->a->st[i];
	quicksort(&sorted_stack, 0, size - 1);
	return (sorted_stack);
}
