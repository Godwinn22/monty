#include "monty.h"

/**
 * m_sub - subtracts the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line: line number of the opcode in the file
 *
 * This function subtracts the top two elements of the stack and
 * updates the stack accordingly. If the stack has less than two
 * elements, it prints an error message and exits the program.
 */
void m_sub(stack_t **head, unsigned int line)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	m = temp->next->n - temp->n;
	temp->next->n = m;
	*head = temp->next;
	free(temp);
}
