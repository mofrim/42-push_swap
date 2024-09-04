#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "quick.h"

int	is_in(long *arr, int val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == val)
			return (1);
	return (0);
}

/* Fills stacks->a with a random array. */
long	*long_rand_arr(int size, unsigned int seed)
{
	int		i;
	int		val;
	long	*a;

	a = malloc(sizeof(long) * size);
	srand(seed);
	val = (double)rand() / (double)RAND_MAX * size * 4;
	i = 0;
	while (i < size)
	{
		while (is_in(a, val, i))
			val = (double)rand() / (double)RAND_MAX * size * 4;
		a[i] = val;
		val = (double)rand() / (double)RAND_MAX * size * 4;
		i++;
	}
	return (a);
}

int	randseed(void)
{
	return ((double)rand() / (double)RAND_MAX * 100000);
}

int main(void)
{
	double	startTime;
	double	endTime;
	double	timeElapsedLo;
	double	timeElapsedHo;
	double	timeElapsedMed;
	double	timeElapsedMy;
	int		runs;
	long	*arr1;
	long	*arr2;
	long	*arr3;
	long	*arr4;
	int		array_size = 500;
	int		seed;

	runs = 10000;
	timeElapsedLo = 0;
	timeElapsedHo = 0;
	timeElapsedMed = 0;
	timeElapsedMy = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	for (int i = 0;i < runs;i++) {
		seed = randseed();
		printf("generating array... // ");
		arr1 = long_rand_arr(array_size, seed);
		arr2 = malloc(sizeof(long) * array_size);
		arr3 = malloc(sizeof(long) * array_size);
		arr4 = malloc(sizeof(long) * array_size);
		memcpy(arr2, arr1, sizeof(long) * array_size);
		memcpy(arr3, arr1, sizeof(long) * array_size);
		memcpy(arr4, arr1, sizeof(long) * array_size);

		printf("qs lomuto... // ");
		startTime = (float)clock()/CLOCKS_PER_SEC;
		quicksort_lomuto(&arr1, 0, array_size - 1);
		endTime = (float)clock()/CLOCKS_PER_SEC;
		timeElapsedLo += endTime - startTime;
		free(arr1);

		printf("qs hoare... // ");
		startTime = (float)clock()/CLOCKS_PER_SEC;
		quicksort_hoare(&arr2, 0, array_size - 1);
		endTime = (float)clock()/CLOCKS_PER_SEC;
		timeElapsedHo += endTime - startTime;
		free(arr2);

		printf("qs med... // ");
		startTime = (float)clock()/CLOCKS_PER_SEC;
		quicksort_median(&arr3, 0, array_size - 1);
		endTime = (float)clock()/CLOCKS_PER_SEC;
		timeElapsedMed += endTime - startTime;
		free(arr3);

		printf("qs my... // ");
		startTime = (float)clock()/CLOCKS_PER_SEC;
		quicksort(&arr4, 0, array_size - 1);
		endTime = (float)clock()/CLOCKS_PER_SEC;
		timeElapsedMy += endTime - startTime;
		free(arr4);
		// printf("i = %d\r", i);
	printf("Lo: %.10lf //", timeElapsedLo / (double)(i+1));
	printf("Ho: %.10lf //", timeElapsedHo / (double)(i+1));
	printf("Med: %.10lf\n", timeElapsedMed / (double)(i+1));
	printf("My: %.10lf\n", timeElapsedMy / (double)(i+1));
	}
	printf("\ntotal time Lo: %.10lf\n", timeElapsedLo / (double)runs);
	printf("total time Ho: %.10lf\n", timeElapsedHo / (double)runs);
	printf("total time Med : %.10lf\n", timeElapsedMed / (double)runs);
	printf("total time My : %.10lf\n", timeElapsedMy / (double)runs);
	return (0);
}

// NOTE: the median approach seems to be fastest for array size of 500. but also
// for bigger ones.
