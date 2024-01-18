#include "monty.h"

transpD_t transpInfo = {NULL, NULL, NULL, 0};
/**
 *main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * 
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	char *data_ct;
	FILE *f_ptr;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *head = NULL;
	unsigned int line = 0;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty f_ptr\n");
		exit(EXIT_FAILURE);
	}
	f_ptr = fopen(argv[1], "r");
	transpInfo.f_ptr = f_ptr;
	if (!f_ptr)
	{
		fprintf(stderr, "Error: can't open f_ptr %s\n", argv[1]);
		exit(EXIT_FAILURE);

	}
	while (read > 0)
	{
		data_ct = NULL;
		read = custom_getline(&data_ct, &size, f_ptr);
		transpInfo.data_ct = data_ct;
		line++;
		if (read > 0)
		{
			m_execute(&head, data_ct, line, f_ptr);
		}
		free(data_ct);
	}
	free_stack(head);
	fclose(f_ptr);
	return (0);
}
