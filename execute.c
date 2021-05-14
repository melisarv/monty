#include "monty.h"

/**
 * execute - executes opcodes
 * @stack: the list
 * @file: file stream "file"
 * Return: stack
*/
void execute(FILE *file, stack_t *stack)
{
	int status;
	char *buffer;
	size_t bfsize;
	char *opcode;
	char *value;
	int line_number;

	status = 0;
	do {
		buffer = NULL;
		bfsize = 0;
		status = getline(&buffer, &bfsize, file);
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		if (status != -1)
		{
			line_number++;
			opcode = strtok(buffer, "\n\t ");

			if (opcode != NULL)
			{
				value = strtok(NULL, "\n\t ");

				if (get_builtins(&stack, opcode, value, line_number) == 0)
				{
					fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
					exit(EXIT_FAILURE);
				}
			}
		}
		if (buffer != NULL)
			free(buffer);
	} while (status != -1);

	if (stack != NULL)
		free_stack(stack);
}
