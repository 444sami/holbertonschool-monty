#include "monty.h"

/**
* _pop - The opcode pop removes the top element of the stack.
*
* @stack: stack where work will be done.
* @line_number: number of lines.
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(1);
	}
	node = *stack;
	*stack = (*stack)->next;
	free(node);
}

/**
* _swap - The opcode swap swaps the top two elements of the stack.
*
* @stack: stack where work will be done.
* @line: number of lines.
*/

void _swap(stack_t __attribute__((unused)) **stack, unsigned int __attribute__((unused)) line)
{
	printf("Entro _swap");
}

/**
* _add - The opcode add adds the top two elements of the stack.
*
* @stack: stack where work will be done.
* @line: number of lines.
*/

void _add(stack_t __attribute__((unused)) **stack, unsigned int __attribute__((unused)) line)
{
	printf("Entro _add");
}

/**
* _nop - The opcode nop doesn’t do anything.
*
* @stack: stack where work will be done.
* @line_number: number of lines.
*/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
