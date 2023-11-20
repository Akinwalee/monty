#include "monty.h"

/**
 * push - Pushes a new node to the top of the stack
 *
 * @n: The data to add to the stack
 *
 * Return: Nothing.
 */

void push(const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = *top;
	new->next = NULL;

	if (*top != NULL)
		(*top)->next = new;

	*top = new;
}
