#include "monty.h"

/**
 * pchar - function that prints characters at the top of the stack
 * @stack: the top of the stack containg characters to be printed
 * @line: the line number of the stack with chars to be printed
 */
void pchar(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - a function that prints strings starting at the top of the stack
 * @stack: top of the stack containing strings to be printed
 * @line: contains the line number of the strings to be printed
 */

void pstr(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	int ascii;
	(void)line;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - function that rotates the stack to the top
 * @stack: the pointer to the top of the stack being rotated
 * @line: the line number in the monty bytes of the stack being rotated
 */
void rotl(stack_t **stack, unsigned int line)
{
	stack_t *curr;
	(void)line;

	if (stack  == NULL || *stack == NULL || (*stack)-> next == NULL)
		return;

	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;

	curr->next = *stack;
	(*stack)->prev = curr;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - function that rotates a stack to the bottom
 * @stack: the pointer to the top of the stack being rotated
 * @line: the line number in the monty bytes of the stack being rotated
 */

void rotr(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
        int ascii;
        (void)line;

        if ((*stack) != NULL)
        {
                tmp = *stack;
                while (tmp->next != NULL)
                {
                        tmp = tmp->next;
                }
                ascii = tmp->n;
                while (tmp->prev != NULL)
                {
                        tmp->n = tmp->prev->n;
                        tmp = tmp->prev;
                }
                tmp->n = ascii;
        }
}
