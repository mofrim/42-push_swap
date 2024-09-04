#include <stdio.h>

void	quicksort_median(long **arr, int left, int right);
void	quicksort(long **arr, int left, int right);
void	quicksort_hoare(long **arr, int left, int right);

int main(void)
{
	int size = 10;
	long arr[10] = {3, 23, 53, -2, 1, 1233, 345, -1232, 0, 42};

	// int size = 10;
	// long arr[10] = {9,8,7,6,5,4,3,2,1,0};

	// int size = 5;
	// long arr[10] = {9,8,7,6,5};

	// int size = 10;
	// long arr[10] = {0,0,0,0,0,0,9,8,7,6};
	
	// int size = 10;
	// long arr[10] = {9,8,7,6,0,0,0,0,0,0};
	
	// int size = 2;
	// long arr[2] = {2,1};

	// int size = 5;
	// long arr[10] = {9,0,0,0,0};

	// int size = 5;
	// long arr[10] = {4,1,3,5,2};

	// long arr[10] = {9,8,7,6,0,0,0,0,0};
	// long arr[10] = {0,0,0,0,0,9,8,7,6};

	// int size = 2;
	// long arr[10] = {1,0};
	long *p;

	p = arr;

	// quicksort_median(&p, 0, size - 1);
	quicksort(&p, 0, size - 1);
	// quicksort_hoare(&p, 0, size - 1);

	printf("\n");
	for (int i = 0;i < size; i++) {
		printf("arr[%d] = %ld\n", i, arr[i]);
	}

	return 0;
}
