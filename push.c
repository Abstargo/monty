#include "monty.h"

void push(int value, unsigned int counter) {
    if (bus.top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Error: Stack overflow\n", counter);
        exit(EXIT_FAILURE);
    } else {
        bus.top++;
        bus.stack[bus.top] = value;
    }
}