#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @value: Value to push
 */
void push(int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}

	new_node->data = value;
	new_node->next = stack;
	stack = new_node;
}
