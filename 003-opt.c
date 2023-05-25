#include "stack.h"

void add_m(stack_t **stack, unsigned int line_number);
void sub_m(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mul_m(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);

/**
 * add_m - Adds the top two values of a stack_t linked list
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 */
void add_m(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		list_el_error(short_stack(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop_m(stack, line_number);
}

/**
 * sub_m - Subtracts the second value from the top of
 * a stack_t linked list by the top value
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 */
void sub_m(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		list_el_error(short_stack(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop_m(stack, line_number);
}

/**
 * div_m - Divides the second value from the top of a
 * stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void div_m(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		list_el_error(short_stack(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		list_el_error(div_fail(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop_m(stack, line_number);
}

/**
 * mul_m - Multiplies the second value from the top of
 * a stack_t linked list by the top value
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 */
void mul_m(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		list_el_error(short_stack(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop_m(stack, line_number);
}

/**
 * mod_m - Computes the modulus of the second value from 
 * top of a stack_t linked list  by the top value
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 */
void mod_m(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		list_el_error(short_stack(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		list_el_error(div_fail(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_m(stack, line_number);
}

