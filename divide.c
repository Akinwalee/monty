#include "monty.h"

/**
 * divide - Divides the second top item of a stack by the top item.
 *
 * @top: Pointer to the top of the stack.
 *
 * Return: void.
 */

void divide(stack_t **top)
{
	stack_t *current = *top;

	current->prev->n /= current->n;
	*top = current->prev;
	free(current);
}
