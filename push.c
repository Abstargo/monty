#include "monty.h"

/**
 * push_function2 - Adds a new node to the stack.
 * @head: Double pointer to the top of the stack.
 * @counter: Line count.
 *
 * Description:
 * This function takes a double pointer to
 * the top of the stack (`head`) and
 * the current line count (`counter`).
 * It checks if a valid integer is provided
 * as an argument and pushes it onto the stack.
 */
void push_function2(stack_t **head, unsigned int counter)
{
	int k = 0, Ss = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			k++;
		for (k = 0; bus.arg[k] != '\0'; k++)
		{
			if (bus.arg[k] > 57 || bus.arg[k] < 48)
			{
				Ss = 1;
			}
		}
		if (Ss == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

