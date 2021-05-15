#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * @val: variable
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int line_num, int val)
{
	stack_t *new;
	(void) line_num;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exitwrap(EXIT_FAILURE, NULL, *stack);
	}
	new->n = val;
	if (*stack != NULL)
		(*stack)->next = new;
	new->next = NULL;
	new->prev = *stack;
	*stack = new;
}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_num)
{
	(void) line_num;

	if (*stack != NULL)
	{
		if ((*stack)->prev != NULL)
		{
			*stack = (*stack)->prev;
			free((*stack)->next);
			(*stack)->next = NULL;
		}
		else
		{
			free(*stack);
			*stack = NULL;
		}
	}
	else
		exitwrap(EXIT_FAILURE, "can't pop an empty stack", *stack);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int temp;
	(void)line_num;

	if (len_stack(*stack) < 2)
		exitwrap(EXIT_FAILURE, "can't swap, stack too short", *stack);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = temp;
}
