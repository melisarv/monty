#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_num)
{
	if (len_stack(*stack) < 2)
		exitwrap(EXIT_FAILURE, "can't add, stack too short", *stack);

	(*stack)->prev->n = (*stack)->n + (*stack)->prev->n;
	pop(stack, line_num);
}

/**
 * sub - subtracts the top two element of the stack
 * @stack: pointer to head of the stack
 * @line_num: file's line number
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_num)
{
	if (len_stack(*stack) < 2)
		exitwrap(EXIT_FAILURE, "can't sub, stack too short", *stack);

	(*stack)->prev->n = (*stack)->prev->n - (*stack)->n;
	pop(stack, line_num);
}

/**
 * divi - divides the top two element of the stack
 * @stack: pointer to head of the stack
 * @line_num: file's line number
 * Return: void
*/
void divi(stack_t **stack, unsigned int line_num)
{
	if (len_stack(*stack) < 2)
		exitwrap(EXIT_FAILURE, "can't div, stack too short", *stack);

	if ((*stack)->n == 0)
		exitwrap(EXIT_FAILURE, "division by zero", *stack);

	(*stack)->prev->n = (*stack)->prev->n / (*stack)->n;
	pop(stack, line_num);
}

/**
 * mul - multiplies the top two element of the stack
 * @stack: pointer to head of the stack
 * @line_num: file's line number
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_num)
{
	if (len_stack(*stack) < 2)
		exitwrap(EXIT_FAILURE, "can't mul, stack too short", *stack);

	(*stack)->prev->n = (*stack)->prev->n * (*stack)->n;
	pop(stack, line_num);
}
