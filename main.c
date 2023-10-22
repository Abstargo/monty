#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
    char *content;
    stack_t *stack = NULL;
    size_t size = 0;
    ssize_t read_line = 1;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    bus.file = fopen(argv[1], "r");
    if (!bus.file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, bus.file);
        bus.content = content;
        counter++;
        if (read_line > 0)
        {
            execute(content, &stack, counter, bus.file);
        }
        free(content);
    }

    free_stack(stack);
    fclose(bus.file);
    return (0);
}