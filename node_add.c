#include "monty.h"

/**
 *addnode - adds a new node at the beginning of a stack_t list
 *@head: double pointer to the head of the stack_t list
 *@n: integer value to be stored in the new node
 */
void addnode(stack_t **head, int n)
{
	stack_t *new; /* create a new node */
	stack_t *temp; /* temporary pointer to traverse the list */

	temp = *head; /* set temp to the current head of the list */
	new = malloc(sizeof(stack_t)); /* allocate memory for the new node */
	if (new == NULL) /* if malloc fails */
	{
		printf("Error: malloc failed\n"); /* print an error message */
		exit(EXIT_FAILURE); /* exit the program */
	}
	if (temp) /* if the list is not empty */
	{
		temp->prev = new; /* set the previous pointer of the current head */
	}
	new->n = n; /* set the integer value of the new node */
	new->next = *head; /* set the next pointer of the new node */
	new->prev = NULL; /* set the previous pointer of the new node */
	*head = new; /* set the head of the list to the new node */
}
