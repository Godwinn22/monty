#include "monty.h"

/**
 * m_rotr - rotates the stack to the bottom
 * @head: pointer to the head of the stack
 * @line: line number of the opcode in the file
 */
void m_rotr(stack_t **head, unsigned int line)
{
	stack_t *temp;
	(void)line;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
