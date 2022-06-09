#include "sort.h"

/**
 * final_merge - merges initial array division
 * @array: original array
 * @size: size of the array
 * @left: pointer to left part
 * @right: pointer to right part
 **/
void final_merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l = size / 2, size_r = size - size_l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);

	printf("[right]: ");
	print_array(right, size_r);

	while (i < size_l && j < size_r)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_l)
		array[k++] = left[i++];

	while (j < size_r)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - uses merge sort in a array
 * @array: array to be sorted
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i, j;
	int left[10000];
	int right[10000];

	if (!array)
		return;

	if (size < 2)
		return;

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (j = mid; j < size; j++)
		right[j - mid] = array[j];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	final_merge(array, left, right, size);
}
