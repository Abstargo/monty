#include "monty.h"

void f_pint(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*head)->n);
}