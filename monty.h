#ifndef __MONTY_H__
#define __MONTY_H__

/* REQUIRED LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* REQUIRED DATA STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);

/* PUSH, PINT, PALL FUNCTIONS */
void push_m(stack_t **head, unsigned int number);
void pall_m(stack_t **head, unsigned int number);
void pint_m(stack_t **head, unsigned int number);

/* OPCODE EXECUTION */
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);

/* MEMORY MANEGEMENT */
void free_stack(stack_t *head);

/* OPERATIONAL FUNCTIONS */
void pop_m(stack_t **head, unsigned int counter);
void swap_m(stack_t **head, unsigned int counter);
void add_m(stack_t **head, unsigned int counter);
void nop_m(stack_t **head, unsigned int counter);
void sub_m(stack_t **head, unsigned int counter);
void div_m(stack_t **head, unsigned int counter);
void mul_m(stack_t **head, unsigned int counter);
void mod_m(stack_t **head, unsigned int counter);
void pchar_m(stack_t **head, unsigned int counter);
void pstr_m(stack_t **head, unsigned int counter);
void rotl_m(stack_t **head, unsigned int counter);
void rotr_m(stack_t **head, __attribute__((unused)) unsigned int counter);

/* ADDING NEW NODES AND QUEUES*/
void new_node(stack_t **head, int n);
void new_queue(stack_t **head, int n);

/* CONVERTION FUNCTONS */
void queue_conv(stack_t **head, unsigned int counter);
void stack_conv(stack_t **head, unsigned int counter);

#endif 	/*__MONTY_H__*/
