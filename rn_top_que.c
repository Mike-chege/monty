#include "monty.h"

/**
 * queue_conv - prints the top
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: Always (void)
*/
void queue_conv(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * new_queue - add node to the tail stack
 * @n: new_value
 * @head: pointer to the head of the stack
 * Return: Always (void)
*/
void new_queue(stack_t **head, int n)
{
	stack_t *new_nnode, *aux;

	aux = *head;
	new_nnode = malloc(sizeof(stack_t));
	if (new_nnode == NULL)
	{
		printf("Error\n");
	}
	new_nnode->n = n;
	new_nnode->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_nnode;
		new_nnode->prev = NULL;
	}
	else
	{
		aux->next = new_nnode;
		new_nnode->prev = aux;
	}
}

/**
 * stack_conv - also displays the top most elelment
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: Always (void) Nothing
*/
void stack_conv(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

