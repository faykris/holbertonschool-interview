#include "lists.h"

/**
 * find_listint_loop - find the loop in a linked list.
 * @head: double pointer to the first element of a linked list.
 *
 * Return: addrress of the node where the loop starts, NULL if there is no node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (!head)
		return (NULL);

	fast = slow = head;

	while (fast && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}
