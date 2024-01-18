#include "monty.h"

/**
 * m_mul - multiplies the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line: line number of the opcode in the file
 */
void m_mul(stack_t **head, unsigned int line)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", c);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	m = temp->n * temp->next->n;
	temp->next->n = m;
	*head = temp->next;
	free(temp);
}
