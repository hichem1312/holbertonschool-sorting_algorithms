#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * @array: array of integers
 * @size: size of array
 * Return: array
 */
void bubble_sort(int *array, size_t size)
{
	int j, test;
	size_t i;

	if (size < 1)
		return;
	while (test)
	{
		test = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				j = array[i];
				array[i] = array[i + 1];
				array[i + 1] = j;
				print_array(array, size);
				test += 1;
			}
		}
	}
}
