#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	stack_t *stack = NULL;
	line_t line = {NULL, NULL};
	int status = EXIT_SUCCESS;

	if (argc != 2)
		usage_error();

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		file_open_error(argv[1]);

	on_exit(free_line, &line);
	on_exit(free_stack, &stack);
	on_exit(close_file, fp);

	parse_file(fp, &stack);

	exit(status);
}
