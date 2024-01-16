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
