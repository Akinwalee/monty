#include "monty.h"

/**
 * mod - Computes the remainder of the division of the
 * second top item on the stack by the top item.
 *
 * @top: Pointer to the top of the stack.
 *
 * Return: void.
 */

void mod(int line_num)
{
	stack_t *current = *top;

	if (!top || !(*top)->prev)
	{
		fprintf(stderr, "L%d: can't div, stack too short.\n", line_num);
		exit(EXIT_FAILURE);
	}
	current->prev->n %= current->n;
	*top = current->prev;
	free(current);
}
