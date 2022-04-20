#include "sort.h"

/**
 * swap_and_print - makes swap values and print array later
 * @array: array to be processed
 * @i: min index
 * @array_p: array to be printed
 * @j: max index
 * @size_p: array size to be printed
 *
 * Return: None
 */
void swap_and_print(int *array, int i, int *array_p, int j, size_t size_p)
{
	int tmp = 0;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	array_p[i] = array[i];
	array_p[j] = array[j];
	print_array(array_p, size_p);
}

/**
 * sift_down - heap sorting implementation
 * @array: array to be processed
 * @size: array size to be processed
 * @i: current index
 * @array_p: array to be printed
 * @size_p: array size to be printed
 *
 * Return: None
 */
void sift_down(int *array, size_t size, int i, int *array_p, size_t size_p)
{
	int max = i, l_child = 2 * i + 1, r_child = 2 * i + 2;

	if (l_child < (int)size && array[l_child] > array[max])
		max = l_child;
	if (r_child < (int)size && array[r_child] > array[max])
		max = r_child;
	if (max != i)
	{
		swap_and_print(array, i, array_p, max, size_p);
		sift_down(array, size, max, array_p, size_p);
	}
}

/**
 * _heap_sort - makes sorting with sift-down
 * @array: array to be processed
 * @size: array size to be processed
 * @array_p: array to be printed
 * @size_p: array size to be printed
 *
 * Return: None
 */
void _heap_sort(int *array, size_t size, int *array_p, size_t size_p)
{
	int i = 0;

	for (i = (size - 1) / 2; i >= 0; i--)
		sift_down(array, size, i, array_p, size_p);
	for (i = (size - 1); i > 0; i--)
	{
		swap_and_print(array, i, array_p, 0, size_p);
		sift_down(array, i, 0, array_p, size_p);
	}
}

/**
 * heap_sort - heap sorting using sift-down method
 * @array: array to be processed
 * @size: array size to be processed
 *
 * Return: None
 */
void heap_sort(int *array, size_t size)
{
	if (array && size > 1)
		_heap_sort(array, size, array, size);
}
