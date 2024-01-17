#include "monty.h"

/**
 * m_push - add element to stack.
 * @arg: The given data.
 *
 * Return: Void.
 */

void m_push(char *arg)
{
	stack_t *node;
	int data;

	if (!verify_input(arg))
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
	stack_t *temp;
	int len = 0, data;

	temp = *h;
	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}

	temp = *h;
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
	free(temp);
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
	int len = 0, data;

	temp = *h;
	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}

	temp = *h;
	data = temp->n + temp->next->n;
	temp->next->n = data;
	*h = temp->next;
	free(temp);
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
