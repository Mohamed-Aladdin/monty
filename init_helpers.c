#include "monty.h"

/**
 * check_input - check the input line.
 * @line: The given argument string.
 *
 * Return: true or false
 */

bool check_input(char *line)
{
	int i;

	if (!line || (line[0] != '-' && !isdigit(line[0])))
		return (false);

	for (i = 1; line[i]; i++)
	{
		if (!isdigit(line[i]))
			return (false);
	}

	return (true);
}

/**
 * init_driver - initializes the driver struct.
 *
 * Return: Void.
 */

void init_driver(void)
{
	driver.file = NULL;
	driver.ip = NULL;
	driver.stack = NULL;
	driver.ipn = 1;
	driver.is_queue = false;
}

/**
 * clean_up - cleans and frees all args.
 *
 * Return: Void.
 */

void clean_up(void)
{
	fclose(driver.file);
	free(driver.ip);
	free_build(driver.stack);
}

/**
 * clean_stack - cleans and frees temp stacks.
 * @stack: The given stack.
 *
 * Return: Void.
 */

void clean_stack(stack_t stack)
{
	stack_t *tmp;
	stack_t *pos = stack;

	while (pos)
	{
		tmp = pos;
		pos = pos->next;
		free(tmp);
	}
}
