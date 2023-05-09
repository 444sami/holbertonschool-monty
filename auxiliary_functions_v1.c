#include "monty.h"

void (*get_function_file(char *current_opcode))(stack_t **function, unsigned int line_number)
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
