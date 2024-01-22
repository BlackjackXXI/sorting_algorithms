#include "sort.h"
#include <stdio.h>

/**
 * conquer - Execute the sorting of partitions
 * @array: The array to be sorted
 * @size: The total count of elements in the array
 * @lower: The initial index for sorting (inclusive)
 * @upper: The final index for sorting (inclusive)
 *
 * Returns: The index of the newly sorted partition
 */
size_t conquer(int *array, size_t size, ssize_t lower, ssize_t upper)
{
	ssize_t index = lower;

	while (index < upper)
	{
		if (array[index] < array[upper])
		{
			if (lower != index)
			{
				array[lower] ^= array[index];
				array[index] ^= array[lower];
				array[lower] ^= array[index];
				print_array(array, size);
			}
			lower += 1;
		}
		index += 1;
	}
	if (array[lower] != array[upper])
	{
		array[lower] ^= array[upper];
		array[upper] ^= array[lower];
		array[lower] ^= array[upper];
		print_array(array, size);
	}
	return (lower);
}

/**
 * divide - Segment the array into partitions
 * @array: The array to be segmented
 * @size: The total count of elements in the array
 * @lower: The initial index for segmentation (inclusive)
 * @upper: The final index for segmentation (inclusive)
 */
void divide(int *array, size_t size, ssize_t lower, ssize_t upper)
{
	ssize_t partition;

	if (lower < upper)
	{
		partition = conquer(array, size, lower, upper);
		divide(array, size, lower, partition - 1);
		divide(array, size, partition + 1, upper);
	}
}

/**
 * quick_sort - Carry out the quick sort algorithm
 * @array: The array to be sorted
 * @size: The total count of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size)
		divide(array, size, 0, size - 1);
}
