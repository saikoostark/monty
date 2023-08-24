#include "monty.h"

/**
 * add - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int error = 0;
	int a = 0;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage:  can't add, stack too short\n", line_number);
		return;
	}

	a = temp->n + temp->next->n;
	pop_front(stack);
	pop_front(stack);
	push_front(stack, a);
}

/**
 * nop - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int error = 0;
	int a = 0;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage:  can't sub, stack too short\n", line_number);
		return;
	}

	a = temp->next->n - temp->n;
	pop_front(stack);
	pop_front(stack);
	push_front(stack, a);
}

/**
 * div - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int error = 0;
	int a = 0;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage:  can't div, stack too short\n", line_number);
		return;
	}

	if (temp->n == 0)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage:  division by zero\n", line_number);
		return;
	}

	a = temp->next->n / temp->n;
	pop_front(stack);
	pop_front(stack);
	push_front(stack, a);
}

/**
 * mul - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int error = 0;
	int a = 0;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
	{
		error = EXIT_FAILURE;
		myerror(&error);
		fprintf(stderr, "L%u: usage:  can't mul, stack too short\n", line_number);
		return;
	}

	a = temp->n * temp->next->n;
	pop_front(stack);
	pop_front(stack);
	push_front(stack, a);
}
