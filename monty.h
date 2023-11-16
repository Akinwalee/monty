#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**Global variables**/
extern stack_t head;
extern stack_t top;

/**Opcodes prototypes**/
void push(stack_t **head, stack_t **top, int n);
void pop(stack_t **top);
void print(stack_t **top);
void pint(stack_t **top);
void swap(stack_t **top);
void add(stack_t **top);
void nop(void);
void sub(stack_t **top);
void divide(stack_t **top);
void mul(stack_t **top);
void mod(stack_t **top);
void pchar(stack_t **top);
void pstr(stack_t **top);
void rotl();
void rotr();
void stack();
void queue();
#endif
