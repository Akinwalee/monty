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
					val = strtol(token, &p, 10);
					if (sizeof(val) != sizeof(int) || token == NULL)
					{
						fprintf(stderr, "L%d: usage: push integer.", line_num);
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
					pint();
					return;
				}
				else if (!strcmp(token, "pop"))
				{
					pop();
					return;
				}
				else if (!strcmp(token, "swap"))
				{
					swap();
					return;
				}
				else if (!strcmp(token, "add"))
				{
					add();
					return;
				}
				else if (!strcmp(token, "nop"))
				{
					return;
				}
				else if (!strcmp(token, "sub"))
				{
					sub();
					return;
				}
				else if (!strcmp(token, "div"))
				{
				 	divide();
					return;
				}
				else if (!strcmp(token, "mul"))
				{
					mul();
					return;
				}
				else if (!strcmp(token, "mod"))
				{
					mod();
					return;
				}
				else if (!strcmp(token, "pchar"))
				{
					pchar();
					return;
				}
				else if (!strcmp(token, "pstr"))
				{
					pstr();
					return;
				}
			}

		}
		printf("L%d: unknown instruction %s\n", line_num, token);
		exit(EXIT_FAILURE);
	}
}
