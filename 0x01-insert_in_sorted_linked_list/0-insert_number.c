#include "lists.h"

/**
 * *insert_node -  inserts a number into a sorted singly linked list.
 * @head: double pointer to head of list
 * @number: number to be added into a sorted singly linked list.
 *
 * Return: Address of the new node, on error retrieves NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t *tmp = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);
	tmp = *head;
	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;
	if (new == NULL)
		return (NULL);
	if (tmp->n >= number)
	{
		new->next = tmp;
		*head = new;
		return (new);
	}
	while (tmp->next != NULL)
	{
		if (tmp->next->n >= number)
		{
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
		tmp = tmp->next;
	}
	tmp->next = new;
	return (new);
}
