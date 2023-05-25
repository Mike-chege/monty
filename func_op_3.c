#include "monty.h"

/**
 * nop_m - prints nothing
 * @head: stack head
 * @counter: line_number
 * Return: NOthing
 */
void nop_m(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * pall_m - prints the stack
 * @head: pointer to the head of the stack head
 * @counter: not to be used
 * Return: Nothing
*/
void pall_m(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

