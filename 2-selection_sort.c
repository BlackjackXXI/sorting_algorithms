#include "sort.h"

/**
 * swap_values - Swap the values of two integers.
 * @a: First integer.
 * @b: Second integer.
 */
void swap_values(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_idx, temp;

	if (array != NULL)
	{
		for (i = 0; i < size - 1; i++)
		{
			min_idx = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min_idx])
					min_idx = j;
			}
			if (array[i] != array[min_idx])
			{
				temp = array[i];
				array[i] = array[min_idx];
				array[min_idx] = temp;
				print_array(array, size);
			}
		}
	}
}
