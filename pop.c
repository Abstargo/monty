#include "monty.h"

/**
 * pop_function5 - Removes the top element of the stack.
 * @head: Pointer to pointer to first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void pop_function5(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;
	free(h);
}

