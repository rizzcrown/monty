#include "monty.h" // Replace with the actual header file name

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top (head) of the stack.
 * @line_number: The current line number in the file being read.
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}
