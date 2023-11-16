#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void pstr(stack_t **top)
{
	stack_t *current = *top
	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		putchar((current->n);
		current = current->prev;
	}
	putchar('\n');
}
