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
