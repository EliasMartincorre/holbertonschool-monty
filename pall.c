#include "monty.h"
/**
 * pall - Prints all the values on the stack
 */
void pall(void)
{
	Node *current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
