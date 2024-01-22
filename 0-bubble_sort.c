#include "sort.h"

/**
 * swap_elements - swap two adjacent elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap_elements(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**
 * bubble_sort - sort an array of integers in ascending order using the Bubble Sort algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Description: This function implements the Bubble Sort algorithm to sort
 * an array of integers in ascending order. It modifies the input array
 * and prints the array after each swap operation.
 */
void bubble_sort(int *array, size_t size)
{
	int *position = NULL;
	int swapped = 0;

	if (array && size > 1)
	{
		do {
			position = array;
			swapped = 0;
			do {
				if (position[1] < position[0])
				{
					swap_elements(position, position + 1);
					swapped = 1;
					print_array(array, size);
				}
			} while (++position + 1 < array + size);
		} while (swapped);
	}
}
