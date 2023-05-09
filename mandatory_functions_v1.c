#include "monty.h"

/**
* _push - The opcode push pushes an element to the stack.
*
* @stack: stack where work will be done.
* @line: number of lines.
*/

void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *newNode = NULL;
    
    newNode = malloc(sizeof(stack_t));
    if (!newNode)
    {
        write(STDERR_FILENO, "Error: malloc failed\n", 21);
        exit(EXIT_FAILURE);
    }
    if (!stack)
    {
        newNode->n = line_number;
        newNode->prev = NULL;
        newNode->next = NULL;
        *stack = newNode;
    }
    else
    {
        newNode->n = line_number;
        newNode->prev = NULL;
        newNode->next = *stack;
        if (*stack)
        {
            (*stack)->prev = newNode;
        }
        *stack = newNode;
    }
}

/**
* _pall - The opcode pall prints all the values on the stack, starting from the top of the stack.
*
* @stack: stack where work will be done.
* @line: number of lines.
*/

void _pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
    stack_t *temp = NULL;

	if (*stack)
	{
		while (*stack != NULL)
		{
            if ((*stack)->n != 0)
			    printf("%d\n", (*stack)->n);
			*stack = (*stack)->next;
		}
	}
}

/**
* _pint - The opcode pint prints the value at the top of the stack, followed by a new line.
*
* @stack: stack where work will be done.
* @line: number of lines.
*/

void _pint(stack_t **stack, unsigned int line)
{
    printf("Entro _pint\n");
}