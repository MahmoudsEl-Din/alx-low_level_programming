#include "lists.h"
#include <stdio.h>


size_t count_nodes(const listint_t *slow, const listint_t *fast)
{
	size_t nodes = 1;

	while (fast != slow)
	{
		nodes++;
		slow = slow->next;
		fast = fast->next;
	}

	slow = slow->next;

	while (fast != slow)
	{
		nodes++;
		slow = slow->next;
	}

	return (nodes);
}

/**
 * detect_loop - Detects if there is any loop in the list.
 *
 * @h: A pointer to the head of the list.
 *
 * Return: It returns 0 if there is no loop otherwise it returns
 * the number of nodes in the list.
 *
 */

size_t detect_loop(const listint_t *h)
{
	const listint_t *slow, *fast;

	slow = h->next;
	fast = h->next->next;

	while (fast)
	{
		if (slow == fast)
		{
			slow = h;
			return (count_nodes(slow, fast));
		}

		slow = slow->next;
		fast = fast->next->next;
	}

	return (0);
}
/**
 * print_listint_safe - Prints a listint_t linked list.
 *
 * @head: A pointer that points to the head of the list.
 *
 * Return: Returns the number of nodes in the list.
 *
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, i = 0;

	if (head == NULL)
		return (0);

	nodes = detect_loop(head);

	if (nodes == 0)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			nodes++;
			head = head->next;
		}
	}
	else
	{
		for (; i < nodes; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
