#include "monty.h"
/**
 * free_stack - Frees the stack.
 */
void free_stack(void)
{
	Node *current = stack;
	while (current != NULL)
	{
		Node *temp = current;
		current = current->next;
		free(temp);
	}
}
