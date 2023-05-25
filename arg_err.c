#include "stack.h"

int short_stack(unsigned int line_number, char *op);
int div_fail(unsigned int line_number);
int pop_fail(unsigned int line_number);
int div_fail(unsigned int line_number);
int pchar_fail(unsigned int line_number, char *message);

/**
 * pop_fail - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_fail(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_fail - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Return: EXIT_FAILURE
 */
int pint_fail(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack - Prints monty math function error message
 * for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred
 * Return: EXIT_FAILURE
 */
int short_stack(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_fail - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Return: EXIT_FAILURE
 */
int div_fail(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_fail - Prints pchar error messages for empty stack
 * empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 * Return: EXIT_FAILURE
 */
int pchar_fail(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
