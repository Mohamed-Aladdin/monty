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

	while ((line = getline(&driver.ip, &n, driver.file) != -1))
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
				m_pushq(data);
			else
				m_push(data);
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

void exec_opc(stack_t **h, char *opc)
{
	char *ops;
	int i;

	instruction_t op_fns[] = {
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};
	ops = strtok(opc, "\n\t");

	for (i = 0; op_fns[i].opcode; i++)
	{
		if (strcmp(ops, op_fns[i].opcode) == 0)
		{
			op_fns[i].f(h, driver.ipn);
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
