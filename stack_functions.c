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
	stack_t *h = *stack;
	(void) line_num;

	if (h == NULL)
		exitwrap(EXIT_FAILURE, "can't pop an empty stack", *stack);
	if (h->prev == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		h = h->prev;
		h->next = NULL;
		free(h);
		*stack = h;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack, *ptr;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (h && h->next)
	{
		ptr = h->next;
		if (ptr->next)
			ptr->next->prev = h;
		h->next = ptr->next;
		ptr->prev = NULL;
		ptr->next = h;
		h->prev = ptr;
		*stack = ptr;
	}
}
