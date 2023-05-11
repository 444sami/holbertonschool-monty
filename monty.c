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
    char *current_opcode = NULL;
    stack_t *stack = NULL;
    FILE *file;
    int line_number = 0;
    void (*op_code_callback)(stack_t **stack, unsigned int line_numbers);
    int status = 0;

    if (argc != 2)
        fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

    stack = malloc(sizeof(stack_t));
    if (!stack)
        fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        free(stack);
        exit(EXIT_FAILURE);
    }

    char buffer_current_line[4000];  // Nueva variable para almacenar cada línea

    while (fgets(buffer_current_line, sizeof(buffer_current_line), file))
    {
        line_number++;
        // Eliminar espacios en blanco adicionales al comienzo de la línea
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
    return status;
}

