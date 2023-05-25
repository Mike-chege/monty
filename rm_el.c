#include "monty.h"

/**
 * pop_m - removes an element from stack
 * @head: pointer to teh head of the stack
 * @counter: line_number
 * Return: Always (void)
*/
void pop_m(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}


