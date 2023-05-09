#include "monty.h"

/**
* main - Entry point.
*
* @argc: Cant of params.
* @argv: Array with content of these params.
*
* ! - Explain the function:
* ! This function is the entry point of the program, here it is done the logic for to call the corresponding function.
*   
* Return: status.
*/

int main(int argc, char *argv[])
{
    char *current_opcode = NULL, *buffer_current_line = NULL;
    stack_t *stack = NULL;
    FILE *file;
    ssize_t length = 0;
    unsigned int line_number = 0;
    void (*op_code_callback)(stack_t **stack, unsigned int line_numbers);
    int status = 0;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    stack = malloc(sizeof(stack_t));
    if (!stack)
    {
        write(STDERR_FILENO, "Error: malloc failed\n", 21);
        exit(EXIT_FAILURE);
    }
    
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        free_list(stack);
        exit(EXIT_FAILURE);
    }

    while (getline(&buffer_current_line, &length, file) != -1)
    {
        line_number++;
        current_opcode = strtok(buffer_current_line, " \t\n$");
        if (!current_opcode)
            continue;
        op_code_callback = get_function_file(current_opcode);
        if (!op_code_callback)
        {
            dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, current_opcode);
            fclose(file);
            free_list(stack);
            exit(EXIT_FAILURE);
        }
        op_code_callback(&stack, line_number);
    }
    fclose(file);
    free_list(stack);
    return (status);
}
