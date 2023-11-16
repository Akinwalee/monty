#include "monty.h"

/**
 * add - Adds the top two items of the stack
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void
 */

void add(stack_t **top)
{
	stack_t *current = *top;

	current->prev->n = current->n + current->prev->n;
	*top = current->prev;
	free(current);
}
