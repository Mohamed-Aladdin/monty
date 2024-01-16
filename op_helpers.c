#include "monty.h"

/**
 * m_push - add element to stack.
 * @arg: The given data.
 *
 * Return: Void.
 */

void m_push(char *arg)
{
	if (!check_input(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
	data = atoi(arg);
	node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_up();
		exit(EXIT_FAILURE);
	}
	node->n = data;
	node->next = driver.stack;
	node->prev = NULL;

	if (node->next)
		node->next->prev = node;
	driver.stack = node;
}

/**
 * m_pop - removes an element from the stack.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_pop(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp = *h;

	if (*h)
	{
		*h = (*h)->next;

		if (*h)
			(*h)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
}

/**
 * m_swap - swaps the top two elements of a stack.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_swap(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	int k;
	stack_t *temp = *h;

	if (temp->next && *h)
	{
		k = temp->n;
		temp->n = temp->next->n;
		temp->next->n = k;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack is too short\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
}

/**
 * m_add - adds the top two elements of the stack.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_add(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp;

	if ((*h)->next && *h)
	{
		(*h)->next->n += (*h)->n;
		temp = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack is too short\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
}

/**
 * m_nop - doesn’t do anything.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_nop(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	(void)h;
}

/**
 * m_sub - subtracts top element of stack from second top element of stack.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_sub(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		(*h)->next->n -= (*h)->n;
		freeable = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack is too short\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
}

/**
 * m_div - divides second top element of stack by top element of stack.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_div(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp;

	if (!(*h)->next || !h)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}

	if (*h && (*h)->next)
	{
		(*h)->next->n /= (*h)->n;
		temp = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(temp);
	}
}
