#include "monty.h"

/**
 *m_pall - prints all the values on the stack, starting from the top
 *@head: pointer to the head of the stack
 *@line: line number of the Monty bytecodes file
 */
void m_pall(stack_t **head, unsigned int line)
{
	stack_t *temp;
	(void)line;

	temp = *head;
	if (temp == NULL)
	{
		return;
	}
	/* iterate through the stack and print each value */
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
