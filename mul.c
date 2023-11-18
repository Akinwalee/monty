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

	if (!top || !(*top)->prev)
	{
		fprintf(stderr, "L%d: can't div, stack too short.\n", line_num);
		exit(EXIT_FAILURE);
	}
	current->prev->n *= current->n;
	*top = current->prev;
	free(current);
}
