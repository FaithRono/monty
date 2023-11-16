#include "monty.h"

/**
*line_parse - parse through individual lines from stream
*@buf: line from file
*@line: line number
*Return: Void
*/

int line_parse(char *buf, int line)
{
	char *opcode = NULL, *opvalue = NULL, *delim = " \n";
	int rt_val = 0;

	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buf, delim);
	if (opcode == NULL)
		return (rt_val);
	opvalue = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	opcode_mapping(opcode, opvalue, line, rt_val);
	return (rt_val);
}

/**
*opcode_mapping - links an 'opcode' to corresponding function
*@opcode: operation code
*@opvalue: operation argument
*@line: line umber
*@rt_val: ...
*Return: Void
*/

void opcode_mapping(char *opcode, char *opvalue, unsigned int line, int rt_val)
{
	int i = 0, flag;

	instruction_t opsmap[] = {
	{"push", push},
	{"pall", pall},
	{"pint", show_top},
	{"add", add},
	{"swap", swap},
	{"pop", pop},
	{"nop", nop},
	{"sub", sub},
	{"div", division},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; opsmap[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opsmap[i].opcode) == 0)
		{
			execute(opsmap[i].f, opcode, opvalue, line, rt_val);
			flag = 0;
			/*return;*/
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
*execute - executes an operation based on an opcode
*@index: function to be executed
*@opc: operation code
*@opv: operation argument
*@line: line number in file
*@rt_val: ....
*
*/

void execute(op_func index, char *opc, char *opv, unsigned int line, int rt_val)
{
	stack_t *node;
	int i, flag;

	flag = 1;
	if (strcmp(opc, "push") == 0)
	{
		if (opv != NULL && opv[0] == '-')
		{
			opv = opv + 1;
			flag = -1;
		}
		if (opv == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
		for (i = 0; opv[i] != '\0'; i++)
		{
			if (isdigit(opv[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
		}
		node = newnode(atoi(opv) * flag);
		if (rt_val == 0)
			func(&node, line);
	}
	else
                index(&head, line);
}

/**
 *newnode - creates a new doubly linked list node
 *@n: data to be inserted into node
 *Return: pointer to new node
 */

stack_t *newnode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		fprintf(stderr, "Error: Malloc failed\n");
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
