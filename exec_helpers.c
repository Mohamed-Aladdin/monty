#include "monty.h"

/**
 * read_input - read lines from the file.
 *
 * Return: Void.
 */

void read_input(void)
{
	char *opc, *data;
	ssize_t line;
	size_t n = 0;

	while (line = getline(&driver.ip, &n, driver.file) != -1)
	{
		opc = strtok(driver.ip, " ");

		if (*opc == '\n' || *opc == '#')
		{
			driver.ipn++;
			continue;
		}
		else if (strcmp(opc, "push") == 0)
		{
			data = strtok(NULL, " \n");

			if (driver.is_queue)
				push_queue(data);
			else
				push(data);
		}
		else
			exec_opc(&driver.stack, opc);
		driver.ipn++;
	}
}

/**
 * exec_opc - call fns.
 * @stack: The pointer to the given stack.
 * @opc: The operation to execute.
 *
 * Return: Void.
 */

void exec_opc(stack_t **stack, char *opc)
{
	char *ops;
	int i;

	instruction_t op_fns[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_op},
		{"queue", queue_op},
		{NULL, NULL}
	}
	ops = strtok(opc, "\n\t");

	for (i = 0; op_fns[i].opcode; i++)
	{
		if (strcmp(ops, op_fns[i].opcode) == 0)
		{
			op_fns[i].f(stack, driver.ipn);
			return;
		}
	}
	if (strcmp(opc, "push"))
	{
		fprintf(stderr, "L%u: ", driver.ipn);
		fprintf(stderr, "unknown instruction %s\n", opc);
	}
	else
		fprintf(stderr, "L%u: usage: push integer\n", driver.ipn);
	exit(EXIT_FAILURE);
}
