#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int *pos = NULL;
	int sorted = 0;

	if (array != NULL && size > 1)
	{
		do {
			pos = array;
			sorted = 0;
			do {
				if (pos[1] < pos[0])
				{
					pos[0] ^= pos[1];
					pos[1] ^= pos[0];
					pos[0] ^= pos[1];
					sorted = 1;
					print_array(array, size);
				}
			} while (++pos + 1 < array + size);
		} while (sorted);
	}
}
