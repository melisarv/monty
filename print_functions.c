#include "monty.h"

/**
 * pall - Print all values on the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	(void)line_num;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - Prints value at top of stack.
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}