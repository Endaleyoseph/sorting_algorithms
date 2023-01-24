#include "sort.h"
/**
 * max_num - max number in an array
 * @array: array of ints
 * @size: size of array
 * Return: max number
 */
int max_num(int *array, size_t size)
{
	unsigned int i = 0;
	int max = 0;

	while (i < size)
	{
		if (array[i] > (int)max)
			max = array[i];
		i++;
	}
	return (max);
}
/**
 * count_sort - counting sort algorithm
 * @array: array of ints
 * @size: size of array
 * @pow: power of 10
 */
void count_sort(int *array, size_t size, int pow)
{
	int *copy;
	int counting[10];
	unsigned int i, tmp;

	copy = malloc(size * sizeof(int));
	if (copy == NULL)
		return;

	i = 0;
	while (i < 10)
	{
		counting[i] = 0;
		i++;
	}

	for (i = 0; i < size; i++)
		counting[(array[i] / pow) % 10]++;

	for (i = 1; i < 10; i++)
		counting[i] += counting[i - 1];

	i = size - 1;
	while ((int)i >= 0)
	{
		tmp = (array[i] / pow) % 10;
		copy[counting[tmp] - 1] = array[i];
		counting[tmp]--;
		i--;
	}
	for (i = 0; i < size; i++)
		array[i] = copy[i];
	free(copy);
}
/**
 * radix_sort - radix sorting algorithm
 * @array: array of ints
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int pow = 1;
	int max = max_num(array, size);

	if (size == 0 || size == 1)
		return;

	while (max / pow > 0)
	{
		count_sort(array, size, pow);
		print_array(array, size);
		pow = pow * 10;
	}
}
