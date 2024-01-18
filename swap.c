#include "monty.h"

/**
 * m_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line: Line number of the Monty bytecodes file.
 */
void m_swap(stack_t **head, unsigned int line)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	m = temp->n;
	temp->n = temp->next->n;
	temp->next->n = m;
}
