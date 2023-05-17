#include "monty.h"
/**
 * free_stack - Frees the memory allocated for the stack.
 * @stack: Pointer to the stack.
 */
void free_stack(Node *stack)
{
	Node *current = stack;

	while (current != NULL)
	{
		Node *temp = current;

		current = current->next;
		free(temp);
	}
}
