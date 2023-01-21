#include "sort.h"

/**
 * selection_sort - sorts array o integers
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	int k, x, w;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		k = array[i];
		x = 0;
		for (j = i; j < size; j++)
		{
			if (array[j] < k)
			{
				k = array[j];
				w = j;
				x = 1;
			}
		}
		if (x == 1)
		{
			array[w] = array[i];
			array[i] = k;
			print_array(array, size);
		}
	}
}
