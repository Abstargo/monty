#include "monty.h"

void execute(unsigned int counter)
{
    if (!bus.content || bus.content[0] == '\n' || bus.content[0] == '#')
        return;

    char *op;
    op = strtok(bus.content, " \n\t");

    if (op) {
        if (strcmp(op, "push") == 0) {
            bus.arg = strtok(NULL, " \n\t");
            if (!bus.arg) {
                fprintf(stderr, "L%d: Error: usage: push integer\n", counter);
                fclose(bus.file);
                free(bus.content);
                exit(EXIT_FAILURE);
            }
            int value;
            char *endptr;
            value = strtol(bus.arg, &endptr, 10);
            if (*endptr != '\0' && *endptr != '\n') {
                fprintf(stderr, "L%d: Error: usage: push integer\n", counter);
                fclose(bus.file);
                free(bus.content);
                exit(EXIT_FAILURE);
            }
            push(value, counter);
        } else if (strcmp(op, "pall") == 0) {
            pall(counter);
        } else {
            fprintf(stderr, "L%d: Error: unknown instruction %s\n", counter, op);
            fclose(bus.file);
            free(bus.content);
            exit(EXIT_FAILURE);
        }
    }
}