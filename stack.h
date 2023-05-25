#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);

int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int byte_script(FILE *script_fd);

void list_el_error(int error_code);

/* push, pall, pint */
void push_m(stack_t **stack, unsigned int line_number);
void pall_m(stack_t **stack, unsigned int line_number);
void pint_m(stack_t **stack, unsigned int line_number);
/*pop and swap functions*/
void pop_m(stack_t **stack, unsigned int line_number);
void swap_m(stack_t **stack, unsigned int line_number);

void add_m(stack_t **stack, unsigned int line_number);
void nop_m(stack_t **stack, unsigned int line_number);
void sub_m(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mul_m(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);

void pchar_m(stack_t **stack, unsigned int line_number);
void pstr_m(stack_t **stack, unsigned int line_number);

/* byte convertion */
void rotate_top_val(stack_t **stack, unsigned int line_number);
void rotate_lw_val(stack_t **stack, unsigned int line_number);
void stack_conv(stack_t **stack, unsigned int line_number);
void queue_conv(stack_t **stack, unsigned int line_number);

/* library functions */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* error functions */
int usage_fail(void);
int malloc_fail(void);
/* error functions */
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

int pop_fail(unsigned int line_number);
int pint_fail(unsigned int line_number);
int short_stack(unsigned int line_number, char *op);
int div_fail(unsigned int line_number);
int pchar_fail(unsigned int line_number, char *message);

#endif /* __STACK_H__ */
