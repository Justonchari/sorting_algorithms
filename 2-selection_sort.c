#include "sort.h"
/**
 * selection_sort - this func sorts an array of
 * integers in ascending order using the selection
 * sort algo
 * @array: input array to be sorted
 * @size: size of aan array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, n, min;
	int temp;

	n = size;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}

	}
}
