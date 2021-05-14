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
