/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:48:50 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 13:11:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* Taking the median. */
long	get_pivot(long *arr, int left, int right)
{
	long x;
	long y;
	long z;

	if (right - left < 2)
	{
		if (arr[left] > arr[right])
			return (arr[right]);
		else
			return (arr[left]);
	}
	x = arr[left];
	y = arr[(right - left)/2 + left];
	z = arr[right];
	if ((x < y && y < z) || (z < y && y < x))
		return (y);
	if (( y < x  && x < z ) || ( z < x  &&  x < y))
		return (x);
	return (z);
}

void	swap(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_arr(long *arr, int l, int r)
{
	printf("[\n");
	while (l <= r)
	{
		printf("%ld", arr[l]);
		l++;
		if (l<=r)
			printf(",");
	}
	printf("]\n");
}

int	partition_median(long **arr, int left, int right)
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
			swap(&(*arr)[i], &(*arr)[j]);
		else if (i == j)
			return (j);
		else
			return (j + 1);
	}
}

void	quicksort_median(long **arr, int left, int right)
{
	int	part_indx;

	if (left < right)
	{
		part_indx = partition_median(arr, left, right);
		quicksort_median(arr, left, part_indx - 1);
		quicksort_median(arr, part_indx + 1, right);
	}
}

/* Kind of my own algorithm. Neither Lomuto, nor Hoare. But it can deal with
 * duplicates \o/ */
int	partition(long **arr, int left, int right)
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
void	quicksort(long **arr, int left, int right)
{
	int	part_indx;

	if (left < right)
	{
		part_indx = partition(arr, left, right);
		quicksort(arr, left, part_indx - 1);
		quicksort(arr, part_indx + 1, right);
	}
}

void	quicksort_lomuto(long **arr, int left, int right)
{
	int	part_indx;

	if (left < right)
	{
		part_indx = partition(arr, left, right);
		quicksort_lomuto(arr, left, part_indx - 1);
		quicksort_lomuto(arr, part_indx + 1, right);
	}
}

/* Plain Lomuto. */
int	partition_lomuto(long **arr, int low, int high)
{
	long	pivot;
	int		i;
	int		j;

	pivot = (*arr)[high];
	i = low;
	j = low;

	while (j < high)
	{
	    if ((*arr)[j] <= pivot) 
		{
	        swap(&(*arr)[i], &(*arr)[j]);
			i++;
	    }
		j++;
	}
	swap(&(*arr)[i + 1], &(*arr)[high]);
	return (i + 1);
}

/* Plain Hoare's Algo. Chooses First elem as pivot. Can't deal with duplicates
 */
int	partition_hoare(long **arr, int low, int high)
{
    long	pivot;
    int		i;
	int		j;

	i = low;
	j = high;
	pivot = (*arr)[low];
    while (1)
	{
		while ((*arr)[i] < pivot)
			i++;
		while ((*arr)[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		swap(&(*arr)[i], &(*arr)[j]);
	}
}
void	quicksort_hoare(long **arr, int left, int right)
{
	int	part_indx;

	if (left < right)
	{
		part_indx = partition_hoare(arr, left, right);
		quicksort_hoare(arr, left, part_indx - 1);
		quicksort_hoare(arr, part_indx + 1, right);
	}
}
