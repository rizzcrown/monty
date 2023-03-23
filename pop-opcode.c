#include "monty.h" // Replace with the actual header file name

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the top (head) of the stack.
 * @line_number: The current line number in the file being read.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}
