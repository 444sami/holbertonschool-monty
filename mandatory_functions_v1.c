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
    char *token_number = NULL;

    // ! Numero para agregar a la pila.
    token_number = strtok(NULL, "\t\n$");
    // ! No encontro un numero al lado del push.
    if (!token_number)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free_list(*stack);
        exit(EXIT_FAILURE);
    }

    newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

    // ! Conectamos el nuevo nodo al stack (head) este mismo se lo asignamos al newNode para que sea el primer elmento en la pila.
    newNode->n = atoi(token_number);
	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack)
	{
		(*stack)->prev = newNode;
	}
	(*stack) = newNode;
}

/**
* _pall - The opcode pall prints all the values on the stack, starting from the top of the stack.
*
* @stack: stack where work will be done.
* @line: number of lines.
*/

void _pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
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

void _pint(stack_t __attribute__((unused)) **stack, unsigned int __attribute__((unused)) line)
{
    printf("Entro _pint\n");
}