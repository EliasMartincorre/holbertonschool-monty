#include "monty.h"
#include <ctype.h>

/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */
static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * m_push - Pushes an element to the stack
 * @stack: Double pointer to the beginning of the stack
 * @n: The integer to add to the stack
 *
 * Return: 0 on success, otherwise an error code
 */
int m_push(stack_t **stack, unsigned int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (MALLOC_ERROR);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (0);
}
