#include "monty.h"

/**
 * m_pstr - prints the string starting at the top of the stack,
 * followed by a newline
 * @head: pointer to the head of the stack
 * @line: line number of the current opcode in the file
 */
void m_pstr(stack_t **head, unsigned int line)
{
	stack_t *temp;
	(void)line;

	temp = *head;
	while (temp)
	{
		if (temp->n <= 0 || temp->n >= 128)
		{
			break;
		}
		printf("%c", (char)temp->n);
		temp = temp->next;
	}
	printf("\n");
}
