#include "monty.h"

/**
 *m_add - adds the top two elements of the stack
 *@head: pointer to the head of the stack
 *@line: line number of the Monty bytecodes file
 */
void m_add(stack_t **head, unsigned int line)
{
	stack_t *temp;
	int i = 0, m;

	temp = *head;
	for (; temp; i++)
	{
		temp = temp->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	m = temp->n + temp->next->n;
	temp->next->n = m;
	*head = temp->next;
	free(temp);
}
