#include "monty.h"

/**
 * mod - Computes the remainder of the division of the
 * second top item on the stack by the top item.
 *
 * @top: Pointer to the top of the stack.
 *
 * Return: void.
 */

void mod()
{
	stack_t *current = *top;

	current->prev->n %= current->n;
	*top = current->prev;
	free(current);
}
