#include "monty.h"

void f_push(stack_t **head, unsigned int counter)
{
    int m = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
        {
            m++;
        }
        for (m = 0; bus.arg[m] != '\0'; m++)
        {
            if (bus.arg[m] > 57 || bus.arg[m] < 48)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
        else
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
}