#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: array of integers
 * @size: size of an array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t j;
	int tmp, swp;

	while (1)
	{
		swp = 0;
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swp++;
			}
		}
		if (swp == 0)
			break;
	}
}
