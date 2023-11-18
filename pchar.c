#include "monty.h"

/**
 * pchar - Prints the char of the integer at thetop of the stack.
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void pchar(int line_num)
{
	if (!*top)
	{
	 fprintf(stderr, "L%d: can't pchar, stack empty", line_num);
	 exit(EXIT_FAILURE);
	}
	if ((*top)->n >= 0 && (*top)->n <= 127)
	{
		putchar((*top)->n);
		putchar('\n');
		return;
	}

	fprintf(stderr, "L%d: can't pchar, value out of range", line_num);
	exit(EXIT_FAILURE);
}
