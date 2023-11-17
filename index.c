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

	stack_t *head;
	head = NULL;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		parseOp(line, line_num, &head);
	}

	fclose(file);

	return (0);
}
