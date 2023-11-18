#include "monty.h"

/**
 * sub - Subtracts the top item on the stack from the second top item.
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void sub()
{
	stack_t *current = *top;

	current->prev->n -= current->n;
	*top = current->prev;
	free(current);
}
