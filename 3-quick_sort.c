#include "sort.h"
#include <stdio.h>

/**
 * divide - finds the right partition
 * @array: array
 * @min: the lowest index
 * @max: the highest index
 * @size: size of the array
 *
 * Return: int
 */
size_t divide(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[max];
	i = min - 1;
	for (j = min; j < max; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[max] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[max];
		array[max] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sort - sort
 * @array: array
 * @min: lowest index
 * @max: highest index
 * @size: size of the array
 *
 * Return: void
 */
void sort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = divide(array, min, max, size);
		sort(array, min, pivot - 1, size);
		sort(array, pivot + 1, max, size);

	}
}

/**
 * quick_sort - sorts an array of integers
 * @array:array
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
