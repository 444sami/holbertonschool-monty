#include "monty.h"

/**
* get_fu - This function do the logic for choose the
* corresponding function.
*
* @current_opcode: The tokenized opcode for the test if
* it matches the default opcodes.
*
* Return: The corresponding function
*/

void (*get_fu(char *current_opcode))(stack_t **stack, unsigned int line_number)
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
		temp = stack_to_free->next;
		free(stack_to_free);
		stack_to_free = temp;
	}
}

int
is_number(char *number)
{
	/**
	* ! 1 - Valid.
	* ! 0 - Invalid.
	*/

	int index = 0;

	if ((number[index] < '0' || number[index] > '9') && number[index] != '-')
	{
		return (0);
	}

	index += 1;

	for (; number[index] != '\0'; index++)
	{
		if ((number[index] < '0' || number[index] > '9'))
		{
			return (0);
		}
	}
	return (1);
}
