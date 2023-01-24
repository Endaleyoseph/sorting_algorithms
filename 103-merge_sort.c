#include "sort.h"
#include <stdio.h>

/**
 * print - prints the progress
 * @array: array of integers
 * @side: side of the array
 * @start: strating side
 * @end: ending side
 *
 */

void print(int *array, char *side, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = start; i < end; i++)
	{
		if (i == (end - 1))
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
}

/**
 * top_down - sorts an array using topdown
 * @array: the original array
 * @sortarr: array for sorting
 * @left: left half of an array
 * @right: right half of an array
 *
 */

void top_down(int *array, int *sortarr, size_t left, size_t right)
{
	size_t mid, i, j, k;

	if (right - left <= 1)
		return;

	mid = (right + left) / 2;

	top_down(array, sortarr, left, mid);
	top_down(array, sortarr, mid, right);
	printf("Merging...\n");
	print(array, "left", left, mid);
	print(array, "right", mid, right);

	j = mid;
	i = left;
	for (k = left; k < right; k++)
	{
		if (i < mid && (j >= right || array[i] <= array[j]))
		{
			sortarr[k] = array[i];
			i = i + 1;
		}
		else
		{
			sortarr[k] = array[j];
			j = j + 1;
		}
	}
	print(sortarr, "Done", left, right);
	for (k = left; k < right; k++)
	{
		array[k] = sortarr[k];
	}
}

/**
 * merge_sort - sorts an array of integers
 * @array: aarray sort
 * @size: size of array
 *
 */

void merge_sort(int *array, size_t size)
{
	int *array2;

	if (!(array) || size < 2)
		return;
	array2 = malloc(sizeof(int) * size);
	if (!(array2))
		return;
	top_down(array, array2, 0, size);
	free(array2);
}
