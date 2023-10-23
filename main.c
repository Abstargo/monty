#include "monty.h"
#define _GNU_SOURCE

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter.
 * @argc: Argument counter.
 * @argv: Argument vector.
 *
 * Interprets Monty bytecode from a file.
 *
 * Returns: Always returns 0.
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int coun = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		coun++;

		if (read_line > 0)
			execute(content, &stack, coun, file);

		free(content);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}