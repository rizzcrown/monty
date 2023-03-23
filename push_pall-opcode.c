#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    int n;
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !isdigit(*arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    push_stack(stack, n);
}

/**
 * push_stack - Pushes a value to the top of the stack.
 * @stack: Pointer to the stack.
 * @n: Value to push.
 *
 * Return: Pointer to the new node.
 */
stack_t *push_stack(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
    return (new_node);
}

#include <stdio.h>
#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top of the stack.
 * @stack: A pointer to the top (head) of the stack.
 * @line_number: The current line number in the file being read.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number; // Unused parameter

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
