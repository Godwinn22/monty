#include "monty.h"

/**
 * m_mod - function that implements the modulo operation in monty bytecodes
 * @head: pointer to the beginning of the stack
 * @line: line number of the monty bytecode file
 */
void m_mod(stack_t **head, unsigned int line)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
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
	m = temp->next->n % temp->n;
	temp->next->n = m;
	*head = temp->next;
	free(temp);
}
