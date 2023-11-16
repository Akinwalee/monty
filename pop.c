#include "monty.h"

/**
 * pop - Pops an item from the the top of the stack
 *
 * @top: Pointer to the top of the stack
 *
 * Return: The popped item.
 */

void pop(stack_t **top)
{
	stack_t *current = *top;

	printf("%d\n", current->n);
	*top = current->prev;
	free(current);
}
