#include "monty.h"

/**
 * divide - Divides the second top item of a stack by the top item.
 *
 * @top: Pointer to the top of the stack.
 *
 * Return: void.
 */

void divide(int line_num)
{
	stack_t *current = *top;
	
	if (!top || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short.\n", line_num);
	}
	current->prev->n /= current->n;
	*top = current->prev;
	free(current);
}
