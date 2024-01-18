#include "monty.h"

/**
 *m_execute - Execute Monty bytecode instructions
 *@head: Pointer to the head of the stack
 *@current: The current line of the Monty bytecode file
 *@line: Line number in the Monty bytecode file
 *@f_ptr: File pointer to the Monty bytecode file
 *Return: 0 on success, 1 on failure
 */
int m_execute(stack_t **head, char *current, unsigned int line, FILE *f_ptr)
{
	instruction_t command[] = {
					{"push", m_push},
					{"pall", m_pall},
					{"pint", f_pint},
					{"nop", m_nop},
					{"add", m_add},
					{"sub", m_sub},
					{"div", m_div},
					{"swap", m_swap},
					{"pop", m_pop},
					{"mul", m_mul},
					{"mod", m_mod},
					{"pchar", m_pchar},
					{"pstr", m_pstr},
					{"rotl", m_rotl},
					{"rotr", m_rotr},
					{"queue", f_queue},
					{"stack", m_stack},
					{NULL, NULL}
					};
	unsigned int i = 0;
	char *op;

	op = strtok(current, " \n\t");
	if (op && op[0] == '#')
		return (0);
	transpInfo.argmt = strtok(NULL, " \n\t");
	for (; command[i].opcode && op; i++)
	{
		if (strcmp(op, command[i].opcode) == 0)
		{
			command[i].f(head, line);
			return (0);
		}
	}
	if (op && command[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		fclose(f_ptr);
		free(current);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
