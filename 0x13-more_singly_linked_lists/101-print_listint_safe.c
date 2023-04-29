#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers, even if it has a loop.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	tortoise = head;
	hare = head;

	while (hare != NULL && hare->next != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			count++;
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			break;
		}
	}

	if (hare == NULL || hare->next == NULL)
	{
		count++;
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
	}

	tortoise = tortoise->next;

	while (tortoise != hare)
	{
		count++;
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
	}

	return (count);
}
