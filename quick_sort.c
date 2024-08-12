/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:36:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 23:03:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* copy paste from geeks-for-geeks */

#include "libft/libft.h"
void swap(long* a, long* b) {
    long t = *a;
    *a = *b;
    *b = t;
}

int partition(long **arr, int low, int high) {
  
    // Choose the pivot
    int pivot = (*arr)[high];
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;
    // Traverse arr[low..high] and move all smaller
    // elements on the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if ((*arr)[j] < pivot) {
            i++;
            swap(&(*arr)[i], &(*arr)[j]);
        }
    }
    // Move pivot after smaller elements and
    // return its position
    swap(&(*arr)[i + 1], &(*arr)[high]);
    return (i + 1);
}

// The QuickSort function implementation
void quicksort(long **arr, int low, int high)
{
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);
        // Recursion calls for smaller elements
        // and greater or equals elements
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

/* WARN: dont forget to free!!! */
long *quicksorted_stack(long *arr, int size)
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

int	get_index_sorted(long num, long *sorted_stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (sorted_stack[i] == num)
			return (i);
	return (-1);
}


