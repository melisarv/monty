#include "monty.h"
/**
 * get_builtins - Checks for builtins
 * @stack: Stack passed in acoording to struct prototype
 * @opcode: opcode contents of file
 * @val: value contents of file
 * Return: 1 if builtins exist, 0 if they don't
 */
int get_builtins(stack_t **stack, char *opcode, char *val)
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
			exitwrap(EXIT_FAILURE, "usage: push integer", *stack);

		push(stack, globalvar.line_num, atoi(val));
		return (1);
	}
	else
	{
		while (list[i].opcode != NULL)
		{
			if (strcmp(list[i].opcode, opcode) == 0)
			{
				list[i].f(stack, globalvar.line_num);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
