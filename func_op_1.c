#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: void
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_m}, {"pall", pall_m}, {"pint", pint_m},
				{"pop", pop_m},
				{"swap", swap_m},
				{"add", add_m},
				{"nop", nop_m},
				{"sub", sub_m},
				{"div", div_m},
				{"mul", mul_m},
				{"mod", mod_m},
				{"pchar", pchar_m},
				{"pstr", pstr_m},
				{"rotl", rotl_m},
				{"rotr", rotr_m},
				{"queue", queue_conv},
				{"stack", stack_conv},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

