#include "monty.h"

/**
 * sub - Subtracts the top item on the stack from the second top item.
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void sub(int line_num)
{
	stack_t *current = *top;

	if (!top || !(*top)->prev)
	{
		fprintf(stderr, "L%d: can't sub, stack too short.\n", line_num);
		exit(EXIT_FAILURE);
	}
	current->prev->n -= current->n;
	*top = current->prev;
	free(current);
}
