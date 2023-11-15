#include <stdio.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;

    while ((read = getline(&line, &len, file)) != -1) {
        char *opcode = strtok(line, " \n");
        if (opcode == NULL || opcode[0] == '#') {
            line_number++;
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
            char *value_str = strtok(NULL, " \n");
            if (value_str == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                return EXIT_FAILURE;
            }
	    int value = atoi(value_str);
            push(&stack, value);
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
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            return EXIT_FAILURE;
        }

        line_number++;
    }

    fclose(file);
    if (line)
        free(line);

    return EXIT_SUCCESS;
}
