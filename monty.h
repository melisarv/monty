#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void execute(FILE *file, stack_t *stack);
int get_builtins(stack_t **stack, char *opcode, char *val, unsigned int line);
void push(stack_t **stack, unsigned int line_num, int val);
void pall(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);

void free_stack(stack_t *stack);

#endif
