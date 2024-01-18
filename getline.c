#include "monty.h"

/**
 * custom_getline - A function that reads a line from a file into a buffer
 * @line_ptr: A pointer to a pointer of a character
 * array that will hold the line
 * @size: The size of the buffer pointed to by line pointer
 * @file: The file to read from
 *
 * Description: This function reads a line from a file into a buffer,
 * dynamically allocating more memory for the buffer as needed.
 * It returns the number of bytes read, or -1 on error.
 *
 * Return: The number of bytes read, or -1 on error
 */
ssize_t custom_getline(char **line_ptr, size_t *size, FILE *file)
{
	const size_t chunk_size = 32;
	ssize_t bytes = 0;
	size_t total_bytes = 0;
	int next_char;
	char *new_line_ptr;

	if (*line_ptr == NULL || *size == 0)
	{
		*size = chunk_size;
		*line_ptr = (char *)malloc(*size);
		if (*line_ptr == NULL)
		{
			perror("Error allocating memory");
			return (-1);
		}
	}
	while ((next_char = fgetc(file)) != EOF)
	{
		if (total_bytes >= *size - 1)
		{
			*size += chunk_size;
			new_line_ptr = (char *)realloc(*line_ptr, *size);
			if (new_line_ptr == NULL)
			{
				perror("Error reallocating memory");
				return (-1);
			}
			*line_ptr = new_line_ptr;
		}
		(*line_ptr)[total_bytes] = (char)next_char;
		total_bytes++;
		if (next_char == '\n')
			break;
	}
	if (total_bytes == 0)
		return (-1);
	(*line_ptr)[total_bytes] = '\0';
	bytes = (ssize_t)total_bytes;
	return (bytes);
}
