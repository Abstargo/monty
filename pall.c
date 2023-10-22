#include "monty.h"

void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
    if (h == NULL)
    {
        return (-1);
    }
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}