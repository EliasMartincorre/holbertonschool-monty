#include "monty.h"
/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 */
void pall(const Node *stack)
{
	const Node *current = stack;

	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
