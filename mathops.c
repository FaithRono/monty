#include "monty.h"

/**
 * add - function that adds two top elements of the stack
 * @stack: the top of the stack containing elements being added
 * @line: line number containing the monty codes of the two elements being summed
 */
void add(stack_t **stack, unsigned int line)
{
	int output;
	(void)line;

	if (stack == NULL|| *stack == NULL|| (*stack)->next == NULL)
	{
		fprintf(stderr, "L&d: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	output = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = output;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - is a function that subracts elements at the top of the stack
 * @stack: pointer to the stack containing the elements being omitted
 * @line: line number in the monty bytecodes of the elements being omitted
 */
void sub(stack_t **stack, unsigned int line)
{
	int output;
	(void)line;

        if (stack == NULL|| *stack == NULL|| (*stack)->next == NULL)
        {
                fprintf(stderr, "L&d: can't sub, stack too short\n");
                exit(EXIT_FAILURE);
        }
        *stack = (*stack)->next;
        output = (*stack)->n - (*stack)->prev->n;
        (*stack)->n = output;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}

/**
 * division - function that divides the second top element by the top element
 * @stack: pointer to the stack containing the elemets being divide
 * @line: line number in the monty bytecodes of the elements being divided
 */
void division(stack_t **stack, unsigned int line)
{
	int output = 0;
	(void)line;

	if (stack == NULL|| *stack == NULL|| (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line);
                exit(EXIT_FAILURE);
        }

	*stack = (*stack)->next;
	if ((*stack)->prev->n != 0)
		output = (*stack)->n / (*stack)->prev->n;
	else
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = output;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul - function that  multiplies the second top element with the second top
 * @stack: the pointer to the stack containing the elents being multiplide
 * @line: line number containing the monty codes of the elements being multiplide
 */

void mul(stack_t **stack, unsigned int line)
{
	 int output;
	 (void)line;

        if (stack == NULL|| *stack == NULL|| (*stack)->next == NULL)
        {
                fprintf(stderr, "L&d: can't mul, stack too short\n");
                exit(EXIT_FAILURE);
        }
        *stack = (*stack)->next;
        output = (*stack)->n * (*stack)->prev->n;
        (*stack)->n = output;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}

/**
 * mod - function that  computes the rest of the div of 2nd and top elements
 * @stack: pointer to the stack containing the elements being computed
 * @line: line number containing monty byte codes of the elements being computed
 */
void mod(stack_t **stack, unsigned int line)
{
	int output;
	(void)line;
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
                fprintf(stdout, "L%d: can't mod, stack too short\n", line);
                exit(EXIT_FAILURE);
        }
	if ((*stack)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", line);
                exit(EXIT_FAILURE);
	}
	output = (*stack)->next->n % (*stack)->n;
	pop(stack, line);
	(*stack)->n = output;
}
