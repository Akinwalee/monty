#include "monty.h"

/**
 * pint - Prints the item at the top of the stack
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void
 */

void pint(int line_num)
{
	if (*top)
	{
		printf("%d\n", (*top)->n);
		return;
	}
	fprintf(stderr, "L%d: can't pint, stack empty", line_num);
	exit(EXIT_FAILURE);
}
