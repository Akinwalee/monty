#include "monty.h"

/**
 * pchar - Prints the char of the integer at thetop of the stack.
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void pchar(stack_t **top)
{
	if ((*top)->n >= 0 && (*top)->n <= 127)
	{
		putchar((*top)->n);
		putchar('\n');
	}
}
