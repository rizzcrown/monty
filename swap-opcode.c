#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top (head) of the stack.
 * @line_number: The current line number in the file being read.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
