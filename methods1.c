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
		fprintf(stderr, "L%u: usage: push integer\n", line_number);

		return;
	}

	if (push_front(stack, num) == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "Error: malloc failed\n");
	}
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
		fprintf(stderr, "L%u: usage: can't pint, stack empty\n", line_number);
		return;
	}

	printf("%d\n", temp->n);
}

/**
 * pop - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int error = 0;

	(void)line_number;

	if (temp == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage: can't pop an empty stack\n", line_number);
		return;
	}
	pop_front(stack);
}

/**
 * swap - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int error = 0;
	int a = 0;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage: can't swap, stack too short\n", line_number);
		return;
	}

	a = temp->n;
	temp->n = temp->next->n;
	temp->next->n = a;
}
