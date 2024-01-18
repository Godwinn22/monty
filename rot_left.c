#include "monty.h"

/**
 * m_rotl - rotates the stack to the left
 * @head: pointer to the head of the stack
 * @line: line number of the current opcode in the file
 */
void m_rotl(stack_t **head, unsigned int line)
{
	stack_t *temp, *new_node;
	(void)line;

	temp = *head;
	if (*head == NULL || temp->next == NULL)
	{
		return;
	}
	new_node = (*head)->next;
	new_node->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = new_node;
}
