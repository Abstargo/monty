#include "monty.h"

/**
 * pint_function3 - Prints the top element of the stack.
 * @head: Pointer to pointer to first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void pint_function3(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

