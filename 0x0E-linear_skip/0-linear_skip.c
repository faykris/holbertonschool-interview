#include "search.h"

/**
* linear_skip - search value in a sorted skip list of integers
* @list: skip list head pointer
* @value: to be searched value
*
* Return: head node pointer, NULL if fail
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *result, *tmp;
	char str_msg1[25] = "Value checked at index ";
	char str_msg2[35] = "Value found between indexes ";

	if (!list)
		return (NULL);
	result = list;
	tmp = list;
	while (tmp->express)
	{
		result = tmp;
		tmp = tmp->express;
		printf("%s[%ld] = [%d]\n", str_msg1, tmp->index, tmp->n);
		if (tmp->n >= value)
			break;
		if (tmp->express == NULL)
		{
			result = tmp;
			while (tmp->next)
				tmp = tmp->next;
		}
	}
	printf("%s[%ld] and [%ld]\n", str_msg2, result->index, tmp->index);
	while (result->next && result->index != tmp->index)
	{
		printf("%s[%ld] = [%d]\n", str_msg1, result->index, result->n);
		if (result->n >= value)
			break;
		result = result->next;
	}
	if (result->next == NULL)
		printf("%s[%ld] = [%d]\n", str_msg1, result->index, result->n);
	if (result->n == value)
		return (result);
	return (NULL);
}
