#include "search_algos.h"

/**
 * print_array - prints each step of binary search
 *
 * @array: array pointer where starts to print
 * @min: starter point index to print
 * @size: position array size to be printed
 *
 * Return: None
 */
void print_array(int *array, size_t min, size_t size)
{
	size_t i;

	if (min != size)
	{
		printf("Searching in array: ");
		for (i = min; i < size; i++)
		{
			printf("%d", array[i]);
			if (i != size - 1)
				printf(", ");
			else
				printf("\n");
		}
	}
}

/**
 * recursive_binary - binary search using recursion
 *
 * @array: array pointer to search value
 * @min: minimum value range to search value
 * @max: maximum value range to search value
 * @value: number to be searched in array
 *
 * Return: array index with found value, -1 if not found
 */
int recursive_binary(int *array, size_t min, size_t max, int value)
{
	int mid;

	if (min > max)
		return (-1);

	print_array(array, min, max + 1);

	mid = min + (max - min) / 2;
	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	if (array[mid] == value && array[mid - 1] == value)
		return (recursive_binary(array, min, mid, value));
	if (array[mid] > value)
		return (recursive_binary(array, min, mid, value));
	return (recursive_binary(array, mid + 1, max, value));
}

/**
 * advanced_binary - makes binary search with repeated numbers
 *
 * @array: array pointer to search value
 * @size: array size in positions
 * @value: number to be searched in array
 *
 * Return: array index with found value, -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1 || value < 0)
		return (-1);
	return (recursive_binary(array, 0, size - 1, value));
}
