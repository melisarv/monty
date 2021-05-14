#include "monty.h"

/**
 * free_stack - traverses the stack and frees each member of the stack
 * @stack: the head node of the stack
 * Return: void
*/
void free_stack(stack_t *stack)
{
	while (stack->prev != NULL)
	{
		stack = stack->prev;
		free(stack->next);
	}
	free(stack);
}
