#include "monty.h"

/**
 * free_stack - traverses the stack and frees each member of the stack
 * @stack: the head node of the stack
 * Return: void
*/
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;

	while (stack->prev != NULL)
	{
		stack = stack->prev;
		free(stack->next);
	}
	free(stack);
}

/**
 * check_number - check if the number
 * @value: variable
 * Return: 0 if number exist, 1 if they don't
*/
int check_number(char *value)
{
	int i = 0;

	if (value == NULL)
		return (1);

	if (value != NULL && value[0] == '-')
		i = 1;

	for (; value[i]; i++)
	{
		if (isdigit(value[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * exitwrap - free things and exit the program
 * @exitcode: exit code
 * @exitstring: error string to print
 * @stack: stack
 */
void exitwrap(int exitcode, char *exitstring, stack_t *stack)
{
	stack_t *ptr = stack;

	if (exitstring != NULL)
		fprintf(stderr, "L%d: %s\n", globalvar.line_num, exitstring);

	while (stack != NULL)
	{
		ptr = stack->prev;
		free(stack);
		stack = ptr;
	}

	fclose(globalvar.file);
	exit(exitcode);
}
