#include "monty.h"

/**
 * f_pint - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @line: line number of the current opcode in the file
 */
void f_pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
