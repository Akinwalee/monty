#include "monty.h"

/**
 * print - Prints all items on the stack
 *
 *
 * Return: void.
 */

void print(void)
{
	stack_t *current = *top;

	if (top == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
