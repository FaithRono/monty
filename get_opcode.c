#include "monty.h"

/**
 * extract_opcode - gets the opcode and sets push_arg if it's push
 * @string: the line of code
 *
 * Return: the opcode
 */
char *extract_opcode(char *string)
{
	char *opcode;

	opcode = strtok(string, "\n\t ");
	return (opcode);
}
