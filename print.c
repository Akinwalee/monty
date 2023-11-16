#include "monty.h"

/**
 * print - Prints all items on the stack
 *
 * @head: Pointer to the head of the stack
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void print(stack_t **head, stack_t **top)
{
	stack_t *current = *top;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
