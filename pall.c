#include "monty.h"

/**
 * pall_function1 - Prints all elements of the stack.
 * @head: Pointer to pointer to first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void pall_function1(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
    if (h == NULL)
    {
        return;
    }
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}