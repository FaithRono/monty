#include "monty.h"
#include <stdio.h>
/**
 * push - function that adds node at the end of a stack
 * @stack: pointer to the head node of the stack
 * @line: line number
 * Return: nothing
 */
void push(stack_t **node, __attribute__((unused))unsigned int line)
{
	stack_t *head = NULL;
	stack_t *temp;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}
/**
 * pall - function to print all elements ina stack
 * @stack: pointer to the stack in the struct
 * @line: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *new;

	(void)line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	new = *stack;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
/**
 * pop - function that removes the top element of a stack
 * @stack: the pointer to the stack
 * @line; the line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *new;

	(void)line;

	if (stack == NULL && *stack == NULL)
	{
		fprintf(stderr, "L%d: the stack is empty\n", line);
		exit(EXIT_FAILURE);
	}
	new = *stack;
	*stack = new->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(new);
}
/**
 *swap - swaps the top two elements in the stack
 *@stack: address of pointer to first stack element
 *@line: line number
 *
 */

void swap(stack_t **stack, unsigned int line)
{
	stack_t *top, *tmp_top;
	(void)line;
	if (*stack == NULL || stack ==  NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	tmp_top = top->next;

	top->next = tmp_top->next;
	if (tmp_top->next != NULL)
		tmp_top->next->prev = top;

	tmp_top->prev = top->prev;
	if (top->prev != NULL)
		top->prev->next = tmp_top;

	top->prev = tmp_top;
	tmp_top->next = top;

	*stack = tmp_top;
}
/**
 * nop - function that does nothing
 * @stack: pointer to the top element of the stack
 * @line: the line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line)
{
        (void)stack;
        (void)line;
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
