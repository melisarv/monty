#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

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

/**
 * struct global_var - contains the global variables
 * @buffer: the buffer containing the text into line
 * @line_num: line number where failure occurred
 * @file: file
 *
 * Description: the global variables
*/
typedef struct global_var
{
	char *buffer;
	unsigned int line_num;
	FILE *file;
} globalvar_t;

/** Struct has been declared as global **/
globalvar_t globalvar;


int execute(void);
int get_builtins(stack_t **stack, char *opcode, char *val);

void push(stack_t **stack, unsigned int line_num, int val);
void pall(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);

void add(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void divi(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);

void free_stack(stack_t *stack);
int check_number(char *value);
void exitwrap(int exitcode, char *exitstring, stack_t *stack);
int len_stack(stack_t *stack);

#endif
