#include "monty.h"

/**
 * pint - Prints the item at the top of the stack
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void
 */

void pint(stack_t **top)
{
	if (*top)
		print("%d\n", (*top)->n);
}
