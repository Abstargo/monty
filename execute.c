#include "monty.h"

/**
 * execute - Executes an opcode.
 * @content: Line content.
 * @stack: Pointer to stack.
 * @coun: Line count.
 * @file: Pointer to file stream.
 *
 * Executes the provided opcode. If successful,
 * returns 0; otherwise, returns 1.
 */
int execute(char *content, stack_t **stack, unsigned int coun, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_function2}, {"pall", pall_function1}, {"pint", pint_function3},
				{"pop", pop_function5},
				{"swap", swap_function4},
				{"add", f_add},
				{"nop", nop_function5},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, coun);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", coun, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}