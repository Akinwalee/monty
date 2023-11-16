#include "main.h"

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
	while (top)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
}
