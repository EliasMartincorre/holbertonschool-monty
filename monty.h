#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * struct Node - Node structure for a stack
 * @data: Data of the node
 * @next: Pointer to the next node
 */
typedef struct Node
{
	int data;
	struct Node *next;
} Node;

/* Main function */
int main(int argc, char *argv[]);

/* Monty operations */
void push(int value);
void pall(void);
void free_stack(void);

#endif /* MONTY_H */
