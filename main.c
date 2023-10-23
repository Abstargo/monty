#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter.
 * @argc: Argument counter.
 * @argv: Argument vector.
 *
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t size = 0;
	ssize_t rr = 1;
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

	while (rr > 0)
	{
		cont = NULL;
		rr = getline(&cont, &size, file);
		bus.cont = cont;
		coun++;

		if (rr > 0)
			execute(cont, &stack, coun, file);

		free(cont);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}

