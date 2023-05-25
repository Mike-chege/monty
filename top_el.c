#include "monty.h"

/**
 * pint_m - shows the top most element in the stack
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: Always (void)
 */
void pint_m(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

