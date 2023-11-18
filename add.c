#include "monty.h"

/**
 * add - Adds the top two items of the stack
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void
 */
void add(int line_num)
{
	stack_t *current = *top;

	if (!top || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short.\n", line_num);
		exit(EXIT_FAILURE);
	}
	current->prev->n = current->n + current->prev->n;
	*top = current->prev;
	free(current);
}
