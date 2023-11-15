#include <stdio.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
       	unsigned int line = 1;
	char *opcode;
	char *value_str;
	int value;
	if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        opcode = strtok(line, " \n");
        if (opcode == NULL || opcode[0] == '#') {
            line++;
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
           value_str = strtok(NULL, " \n");
            if (value_str == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line);
                exit(EXIT_FAILURE);
            }
	    value = atoi(value_str);
            push(&stack_t, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(&stack);
        } else if (strcmp(opcode, "pop") == 0) {
            pop(&stack);
        } else if (strcmp(opcode, "swap") == 0) {
            swap(&stack);
        } else if (strcmp(opcode, "add") == 0) {
            add(&stack);
	       }
	} else if (strcmp(opcode, "nop") == 0) {
            nop(&stack);
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
            exit(EXIT_FAILURE);
        }

        line++;
    }

    fclose(file);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}
