#include "sort.h"

/**
 * swap_values - this func swaps the values inside
 * two variables
 * @x: pointer to the first value
 * @y: pointer to the second value
 */
void swap_values(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition - this func splits the array
 * into two partitions
 * @array: the array to be partitioned
 * @lb: the lower bound
 * @ub: the upper bound
 * @size: the size
 * Return: pivot
 */
int partition(int *array, int lb, int ub, size_t size)
{
	int pivot = array[ub];
	int x = lb - 1, y;

	for (y = lb; y <= ub; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap_values(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}

/**
 * quick_sort_recursive - this func sorts the array
 * using recursion
 * @array: the array to be sorted
 * @lb: the lowerbound index
 * @ub: the upperbound index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int lb, int ub, size_t size)
{
	int pivot;

	if (lb < ub)
	{
		pivot = partition(array, lb, ub, size);
		quick_sort_recursive(array, lb, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, ub, size);
	}
}

/**
 * quick_sort - this func sorts an array using the
 * quick sort algo
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
