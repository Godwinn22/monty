#include "monty.h"

/**
 * m_pop - Removes the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line: Line number of the Monty bytecodes file.
 */
void m_pop(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
