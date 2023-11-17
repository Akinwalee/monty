#include "monty.h"

/**
 * pop - Pops an item from the the top of the stack
 *
 * @top: Pointer to the top of the stack
 *
 * Return: The popped item.
 */

void pop(int line_num)
{
	stack_t *current = *top;
	
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack.", line_num);
	}
	printf("%d\n", (*top)->n);
	*top = current->prev;
	free(current);
}
