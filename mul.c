#include "monty.h"

/**
 * mul - Multiplies the item at the top of thestack with the second top item.
 *
 * @top: Pointer to the top of the stack.
 *
 * Return: void.
 */

void mul(int line_num)
{
	stack_t *current = *top;

	current->prev->n *= current->n;
	*top = current->prev;
	free(current);
}
