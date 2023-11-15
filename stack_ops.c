#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

/**
 * push - function that pushes elements into stack
 * @stack: pointer to the stack
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Mem allocation failed\n");
			exit(EXIT_FAILURE);
	}
	new_node->n = line;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}
/**
 * pall - function to print all elements in a stack
 * @stack: pointer to the head node in the stack
 */
void pall(stack_t **stack)
{
	stack_t *current;

	current = *stack;
	while (current == NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - function to print integers in the stack
 * @stack: pointer to a node in the string
 * @line: the line number
 */
void pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: Stack is empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - function to delete element in the stack
 * @stack: pointer to a node in the system
 * @line: the line number
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (*stack == NULL)
        {
                fprintf(stderr, "L%d: Stack is empty\n", line);
                exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * swap - function that swaps two nodes
 * @stack: pointer a node in the stack
 * @line: line number
 */
void swap(stack_t **stack, unsigned int line)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Stack is empty\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
/**
 * nop - pass and do nothing.
 *
 * @stack: Pointer to the head
 * @line: opcode line number
 */
void nop(stack_t **stack, unsigned int line)
{
        (void)stack;
        (void)line;
}
