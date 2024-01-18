#include "monty.h"

/**
 * m_push - function that pushes
 * @head: the head struct
 * @c: line number of the Monty bytecodes file
 */
void m_push(stack_t **head, unsigned int c)
{
	int n, i = 0, m = 0;

	if (transpInfo.argmt)
	{
		if (transpInfo.argmt[0] == '-')
			i++;
		while (transpInfo.argmt[i] != '\0')
		{
			if (transpInfo.argmt[i] > 57 || transpInfo.argmt[i] < 48)
			{
				m = 1;
			}
			i++;
		}
		if (m == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(transpInfo.f_ptr);
			free(transpInfo.data_ct);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(transpInfo.f_ptr);
			free(transpInfo.data_ct);
			free_stack(*head);
			exit(EXIT_FAILURE);
	}
	n = atoi(transpInfo.argmt);
	if (transpInfo.trficIdx == 0)
	{
		addnode(head, n);
	}
	else
	{
		addqueue(head, n);
	}
}
