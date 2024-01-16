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

	if (*h && (*h)->next)
	{
		(*h)->next->n -= (*h)->n;
		temp = *h;
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

/**
 * m_mul - multiplies second top element of stack with top element of stack.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_mul(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp;

	if (*h && (*h)->next)
	{
		(*h)->next->n *= (*h)->n;
		temp = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", driver.ipn);
		clean_up();
		exit(EXIT_FAILURE);
	}
}

/**
 * m_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_mod(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *temp;

	if (!*h || !(*h)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", driver.ipn);
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
		(*h)->next->n %= (*h)->n;
		temp = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(temp);
	}
}
