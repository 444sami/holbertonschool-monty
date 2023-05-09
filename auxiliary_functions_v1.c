#include "monty.h"

/**
* get_function_file - This function do the logic for choose the corresponding function.
*
* @current_opcode: The tokenized opcode for the test if it matches the default opcodes.
* @stack: reference to a stack to a function that performs an operation on the stack
* @line_number: number of lines.
*/

void (*get_function_file(char *current_opcode))(stack_t **stack, unsigned int line_number)
{
    int index = 0;

    instruction_t struct_rules[] = {
        { "push", _push },
        { "pall", _pall },
        { "pint", _pint },
        { "pop",  _pop },
        { "swap", _swap },
        { "add",  _add },
        { "nop",  _nop },
        { NULL, NULL }
    };

    for (; struct_rules[index].opcode; index++)
    {
        if (strcmp(struct_rules[index].opcode, current_opcode) == 0)
        {
            return (struct_rules[index].f);
        }
    }
    return (NULL);
}

/**
* free_list - Free memory of doubly linked list.
*
* @stack_to_free: stack to free.
*/

void free_list(stack_t *stack_to_free)
{
    stack_t *temp;

    while (stack_to_free != NULL)
    {
        temp = stack_to_free;
        stack_to_free = stack_to_free->next;
        free(temp);
    }
}
