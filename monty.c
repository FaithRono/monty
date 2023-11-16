#include "monty.h"
#include <stdio.h>

stack_t *head = NULL;

/**
 * main - the entry point of the program
 * @argc: the argument count
 * @argv: the argument vector
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char reg[1024];
	unsigned int line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL || argv[1] == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(reg, 1024, file) != NULL)
	{
		parse(reg);
		line++;
	}


	fclose(file);
	freenodes();
	return (0);
}

/**
*freenodes - frees nodes
*Return: void
*/

void freenodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * queue - adds a new node to the queue
 * @stack: pointer to node to be added
 * @line: line number
 */

void queue(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	(void)line;

	if (stack  == NULL || *stack  == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *stack;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;

}
