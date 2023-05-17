#include "monty.h"

/**
 * main - Entry point of the Monty program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	Node *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char line[MAX_LINE_LENGTH];
	int line_number = 1;

	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}

		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \t\n");

			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(stack);
				fclose(file);
				return (EXIT_FAILURE);
			}
			int value = atoi(arg);

			if (value == 0 && arg[0] != '0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(stack);
				fclose(file);
				return (EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			fclose(file);
			return (EXIT_FAILURE);
		}

		line_number++;
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
