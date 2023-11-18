#include "monty.h"

/**
 * parseOp - Parses each line of a Monty file
 *
 * @line: Line of monty bytecode
 * @line_num: Line number of the current line
 *
 * Return: void
 */

void parseOp(char *line, int line_num)
{
	char *token;
	char *codes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", "sub", "div", "mul", "mod"};
	int i;
	int val;
	char *p;

	while (isspace(*line))
		line++;

	token = strtok(line, " \n");

	if (token)
	{
		for (i = 0; i < (int)(sizeof(codes) / sizeof(codes[0])); i++)
		{
			if (!strcmp(token, codes[i]))
			{
				if (!strcmp(token, "push"))
				{
					token = strtok(NULL, " \n");
					if (token == NULL)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_num);
						exit(EXIT_FAILURE);
					}
					val = strtol(token, &p, 10);
					if (*p != '\0')
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_num);
						exit(EXIT_FAILURE);
					}
					push(val);
					return;
				}
				else if (!strcmp(token, "pall"))
				{
					print();
					return;
				}
				else if (!strcmp(token, "pint"))
				{
					if (!(*top))
					{
						fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
						exit(EXIT_FAILURE);
					}
					pint();
					return;
				}
				else if (!strcmp(token, "pop"))
				{
					if (!(*top))
					{
						fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
						exit(EXIT_FAILURE);
					}
					pop();
					return;
				}
				else if (!strcmp(token, "swap"))
				{
					if (*top == NULL || (*top)->prev == NULL)
					{
						fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
						exit(EXIT_FAILURE);
					}
					swap(line_num);
					return;
				}
				else if (!strcmp(token, "add"))
				{
					if (!*top || (*top)->prev == NULL)
					{
						fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
						exit(EXIT_FAILURE);
					}
					add();
					return;
				}
				else if (!strcmp(token, "nop"))
				{
					nop();
					return;
				}
				else if (!strcmp(token, "sub"))
				{
					if (!(*top) || !(*top)->prev)
					{
					fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
					exit(EXIT_FAILURE);
					}
					sub();
					return;
				}
				else if (!strcmp(token, "div"))
				{
					if (!(*top) || (*top)->prev == NULL)
					{
						fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
						exit(EXIT_FAILURE);
					}
					if ((*top)->n == 0)
					{
						fprintf(stderr, "L%d: division by zero\n", line_num);
						exit(EXIT_FAILURE);
					}
				 	divide();
					return;
				}
				else if (!strcmp(token, "mul"))
				{
					if (!(*top) || !(*top)->prev)
					{
						fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
						exit(EXIT_FAILURE);
					}
					mul();
					return;
				}
				else if (!strcmp(token, "mod"))
				{
					if (!(*top) || !(*top)->prev)
					{
						fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
						exit(EXIT_FAILURE);
					}

					if ((*top)->n == 0)
					{
						fprintf(stderr, "L%d: division by zero\n", line_num);
						exit(EXIT_FAILURE);
					}
					mod();
					return;
				}
				else if (!strcmp(token, "pchar"))
				{
					pchar(line_num);
					return;
				}
				else if (!strcmp(token, "pstr"))
				{
					pstr();
					return;
				}
			}
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
		exit(EXIT_FAILURE);
	}
}
