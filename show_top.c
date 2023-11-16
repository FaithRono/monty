#include "monty.h"
/**
 * show_top - prints the element at the top of the stack
 *
 * @stack: Pointer to head
 * @line: opcode line number
 */

void show_top(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
