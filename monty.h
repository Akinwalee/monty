#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
extern stack_t **top;

/**Function Prototype**/
void parseOp(char *line, int line_num);

/**Opcodes prototypes**/
void push(int n);
void pop(int);
void print(void);
void pint(int);
void swap(int);
void add(int);
void nop(void);
void sub(int);
void divide(int);
void mul(int);
void mod(int);
void pchar(int);
void pstr(void);
void rotl(int);
void rotr(int);
void stack(int);
void queue(int);
#endif
