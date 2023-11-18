#include "monty.h"

/**
 * pop - Pops an item from the the top of the stack
 *
 * @top: Pointer to the top of the stack
 *
 * Return: The popped item.
 */

void pop(void)
{
	stack_t *current = *top;

	printf("%d\n", (*top)->n);
	*top = current->prev;
	free(current);
}
