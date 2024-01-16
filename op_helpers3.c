/**
 * m_rotr - rotates the stack to the bottom.
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_rotr(stack_t **h, __attribute__((unused))unsigned int ipn)
{
	stack_t *ft, *sd;

	if (!(*h) || !(*h)->next)
	{
		return;
	}

	ft = *h;

	while (ft->next->next)
	{
		ft = ft->next;
	}
	sd = ft->next;
	ft->next = NULL;
	(*h)->prev = sd;
	sd->next = *h;
	sd->prev = NULL;
	*h = sd;
}

/**
 * m_stack - sets the format of the data to a stack (LIFO).
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_stack(stack_t **h, unsigned int ipn)
{
	(void)h;
	(void)ipn;
	driver.is_queue = false;
}

/**
 * m_queue - sets the format of the data to a queue (FIFO).
 * @h: The given stack.
 * @ipn: The input line number.
 *
 * Return: Void.
 */

void m_queue(stack_t **h, unsigned int ipn)
{
	(void)h;
	(void)ipn;
	driver.is_queue = true;
}

/**
 * m_pushq - add element to queue.
 * @arg: The given data.
 *
 * Return: Void.
 */

void m_pushq(char *arg)
{
	stack_t *node, *pos;
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
	pos = driver.stack;
	node->n = data;
	node->next = NULL;
	if (!pos)
	{
		node->prev = NULL;
		driver.stack = node;
		return;
	}
	while (pos->next)
	{
		pos = pos->next;
	}
	pos->next = node;
	node->prev = pos;
}
