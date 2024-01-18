#include "monty.h"

/**
 * m_pchar - prints the char at the top of the stack, followed by a new line
 * @head: pointer to the head of the stack
 * @line: line number of the opcode in the file
 */
void m_pchar(stack_t **head, unsigned int line)
{
	stack_t *temp;

	temp = *head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n >= 128 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		fclose(transpInfo.f_ptr);
		free(transpInfo.data_ct);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(temp->n));
}
