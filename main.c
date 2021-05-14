#include "monty.h"

/**
 * main - function that initializes the program
 * @argc: number of arguments given to the executable
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	globalvar.file = fopen(argv[1], "r");
	if (globalvar.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	execute();

	return (EXIT_SUCCESS);
}
