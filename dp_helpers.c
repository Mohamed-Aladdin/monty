#include "monty.h"

/**
 * m_pall - print all elements.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_pall(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp = *h;

	if (!*h)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * m_pint - print the data in the stack.
 * @h: The given stack.
 * @ipn: The input line number.
 */

void m_pint(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp = *h;

	if (*h)
		printf("%d\n", temp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
}
