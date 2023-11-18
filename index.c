#include "monty.h"

/**
 * main - Entry point of the program.
 *
 * Return: 0 for Success 1 for failure
 */
stack_t **top = NULL;
int main(int argc, char **argv)
{
	FILE *file;
	char line[MAX];
	int line_num = 0;
	stack_t *temp;

	top = malloc(sizeof(stack_t *));
	*top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		parseOp(line, line_num);
	}

	while((*top)->prev)
	{
		temp = *top;
		*top = temp->prev;
		free(temp);
	}

	fclose(file);

	return (0);
}
