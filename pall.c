#include "monty.h"

void pall(unsigned int counter) {
    for (int i = bus.top; i >= 0; i--) {
        printf("%d\n", bus.stack[i]);
    }
}