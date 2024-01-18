#include "monty.h"

/**
 * m_div - Divides the second top element of the stack by the top element.
 * @head: Pointer to the head of the stack.
 * @line: Line number of the Monty bytecodes file.
 */
void m_div(stack_t **head, unsigned int line)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	m = temp->next->n / temp->n;
	temp->next->n = m;
	*head = temp->next;
	free(temp);
}
