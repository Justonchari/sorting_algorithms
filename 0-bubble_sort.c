# include "sort.h"
/**
 * bubble_sort - this func sorts an array of integers
 * in ascending order using the bubble sort algorithm
 * @array: array to sort
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, n = size;
	int flag, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 1;
				print_array(array, n);
			}
		}
		if (flag == 0)
			break;
	}
}
