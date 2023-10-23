#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the first node of the stack.
 *
 * Return: None.
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * f_stack - Free the stack.
 * @head: Pointer to the first node (unused).
 * @counter: Line counter (unused).
 *
 * Return: None.
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus.lifi = 0;
}