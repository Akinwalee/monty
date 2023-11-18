#include "monty.h"

/**
 * swap - Swaps the top two items of the stack.
 *
 * @top: Pointer to the top of the stack
 *
 * Return: void.
 */

void swap(int line_num)
{
	stack_t *current = *top;
	stack_t *second = (*top)->prev;

	if (!top || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_num);
		exit(EXIT_FAILURE);
	}
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
