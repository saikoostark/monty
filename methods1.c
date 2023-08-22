#include "monty.h"

/**
 * push - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num = 0, error = 0;
	(void)line_number;

	if (checkNumber(strtok(NULL, " "), &num) == -1)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage: push integer", line_number);

		return;
	}
	push_front(stack, num);
}

/**
 * pall - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int error = 0;

	(void)line_number;

	if (temp == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage: can't pint, stack empty", line_number);

		return;
	}

	printf("%d\n", temp->n);
}
