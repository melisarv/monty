#include "monty.h"
/**
 * get_builtins - Checks for builtins
 * @stack: Stack passed in acoording to struct prototype
 * @opcode: opcode contents of file
 * @val: value contents of file
 * @line: line number of the parsed command
 * Return: 1 if builtins exist, 0 if they don't
 */
int get_builtins(stack_t **stack, char *opcode, char *val, unsigned int line)
{
	unsigned int i = 0;

	instruction_t list[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{NULL, NULL}
	};

	if (strcmp("push", opcode) == 0)
	{
		if (check_number(val))
		{
			free_stack(*stack);
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
		push(stack, line, atoi(val));
		return (1);
	}
	else
	{
		while (list[i].opcode != NULL)
		{
			if (strcmp(list[i].opcode, opcode) == 0)
			{
				list[i].f(stack, line);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
