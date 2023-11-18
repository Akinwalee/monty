#include "monty.h"

/**
 * swap - Swaps the top two items of the stack.
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void swap(void)
{
	stack_t *current = *top;
	stack_t *second = (*top)->prev;

	current->prev = second->prev;
	second->next = current->next;
	current->next = second;
	second->prev = current;

	/**Updating the adjacent nodes**/
	if (current->prev)
		current->prev->next = current;
	if (second->next)
		second->next->prev = second;

	*top = second;
}
