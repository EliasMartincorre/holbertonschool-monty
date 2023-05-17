#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @value: The value to be pushed.
 */
void push(Node **stack, int value)
{
	Node *new_node = malloc(sizeof(Node));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->data = value;
	new_node->next = *stack;
	*stack = new_node;
}
