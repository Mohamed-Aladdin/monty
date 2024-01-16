#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct driver_s - global struct to hold stack related info.
 * @file: input file.
 * @ip: input line.
 * @stack: the given stack.
 * @ipn: line number in buffer.
 * @is_queue: queue boolean.
 *
 * Description: global struct to hold stack related info.
 */

typedef struct driver_s
{
	FILE *file;
	char *ip;
	stack_t *stack;
	unsigned int ipn;
	bool is_queue;
} driver_t;

extern driver_t driver;

/* Main Helpers */
bool check_input(char *line);
void init_driver(void);
void clean_up(void);
void clean_stack(stack_t *h);
void read_input(void);
void exec_opc(stack_t **h, char *opc);

/* Display Tasks Functions */
void m_pall(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_pint(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_pchar(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_pstr(stack_t **h, __attribute__((unused))unsigned int ipn);

/* Operation Tasks Functions */
void m_push(char *arg);
void m_pop(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_swap(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_add(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_nop(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_sub(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_div(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_mul(stack_t **h, __attribute__((unused))unsigned int ipn);
void m_mod(stack_t **h, __attribute__((unused))unsigned int ipn);

#endif /* _MONTY_H_ */
