#include "sort.h"

/**
 * partition - divides an array at the pivot
 * @array: array of integers
 * @lo: lowest index
 * @hi: highest index
 * @size: size of an array
 * Return: pivot index position
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot, tmp;

	i = lo - 1;
	pivot = array[hi];

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	i++;
	if (i != hi)
	{
		array[hi] = array[i];
		array[i] = pivot;
		print_array(array, size);
	}

	return (i);
}

/**
 * sort - sorts an array using partinions
 * @array: array of integers
 * @lo: lowest index
 * @hi: highest index
 * @size: size of an array
 *
 */

void sort(int *array, int lo, int hi, size_t size)
{
	int par;

	if (lo >= hi || lo < 0)
		return;

	par = partition(array, lo, hi, size);

	sort(array, lo, par - 1, size);
	sort(array, par + 1, hi, size);
}

/**
 * quick_sort - uses lomuto scheme to sort an array
 * @array: array of integers
 * @size: size of an array
 *
 */

void quick_sort(int *array, size_t size)
{
	int i = 0;
	int hi = size - 1;

	if (array == NULL || size < 2)
		return;
	sort(array, i, hi, size);
}
