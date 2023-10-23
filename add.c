#include "monty.h"

/**
 * f_add - Adds the first two elements of the stack.
 * @head: Pointer to pointer to the first node.
 * @coun: Line counter.
 *
 * Description:
 * This function takes a pointer to the pointer
 * of the first node (`head`) and
 * the current line count (`coun`).
 * It adds the values of the first two elements
 * on the stack and replaces the second element with the result.
 *
 * Return: None.
 */
void f_add(stack_t **head, unsigned int coun)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", coun);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

