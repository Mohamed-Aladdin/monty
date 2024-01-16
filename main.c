#include "monty.h"

/**
* main - entry point.
* @argc: number of args
* @argv: array of args.
* Return: 0 or EXIT_FAILURE.
*/

int main(int argc, char **argv)
{
	FILE file;

	init_driver();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	driver.file = fopen(argv[1], "r");

	if (!driver.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_input();
	clean_up();

	return (EXIT_SUCCESS);
}
