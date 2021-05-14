#include "monty.h"

/**
 * execute - executes opcodes
 * Return: 0 if successful, 1 if failed
*/

int execute(void)
{
	stack_t *stack = NULL;
	int status;
	size_t bfsize;
	char *opcode;
	char *value;

	status = 0;
	do {
		globalvar.buffer = NULL;
		bfsize = 0;
		status = getline(&globalvar.buffer, &bfsize, globalvar.file);
		if (status != -1)
		{
			globalvar.line_num++;
			opcode = strtok(globalvar.buffer, "\n\t ");

			if (opcode != NULL)
			{
				value = strtok(NULL, "\n\t ");

				if (get_builtins(&stack, opcode, value) == 0)
				{
					fprintf(stderr, "L%u: unknown instruction %s\n",
					globalvar.line_num, opcode);
					exitwrap(EXIT_FAILURE, NULL, stack);
				}
			}
		}
		if (globalvar.buffer != NULL)
			free(globalvar.buffer);

	} while (status != -1);

	exitwrap(EXIT_SUCCESS, NULL, stack);
	return (0);
}
