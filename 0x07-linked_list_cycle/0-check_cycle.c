#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - check if cycle exist on a single linked list
 * @list: pointer of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *l = list, *t = list;

	if (t == NULL)
		return (0);
	if (t->next == NULL)
		return (0);
	l = l->next;
	if (l->next == NULL)
		return (0);
	l = l->next;
	while (l != t)
	{
		t = t->next;
		l = l->next;
		if (l->next == NULL)
			return (0);
		l = l->next;
		if (l->next == NULL)
			return (0);
	}
	return (1);
}
