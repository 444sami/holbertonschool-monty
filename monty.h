#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Libraries for to use File I/0 */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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


/* Functions to develop*/

void _push(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);

/* Functions to develop auxiliary functions*/

void (*get_function_file(char *))(stack_t **, unsigned int);
void free_list(stack_t *);
int _verifyNumber(char *);

#endif