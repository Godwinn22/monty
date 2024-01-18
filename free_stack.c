#include "monty.h"

/**
 * free_stack - function that frees a stack_t list
 * @head: Pointer to the head of the list
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (temp)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
