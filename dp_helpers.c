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
 *
 * Return: Void.
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

/**
 * m_pchar - prints the char at the top of the stack, followed by a new line.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_pchar(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	if (!(*h))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
	if ((*h)->n < 0 || (*h)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*h)->n);
}

/**
 * m_pstr - prints string starting at top of stack, followed by a new line.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_pstr(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *pos = *h;

	while (pos && pos->n > 0 && pos->n <= 127)
	{
		putchar(pos->n);
		pos = pos->next;
	}
	putchar('\n');
}
