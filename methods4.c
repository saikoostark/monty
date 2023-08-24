#include "monty.h"

/**
 * rotl - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int a = 0;

	if (temp == NULL)
		return;

	a = temp->n;

	(void)line_number;
	while (temp && temp->next)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	temp->n = a;
}

/**
 * rotr - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = back(stack);
	int a = 0;

	if (temp == NULL)
		return;

	a = temp->n;
	(void)line_number;

	while (temp && temp->prev)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}
	temp->n = a;
}

/**
 * _stack - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	checkpush("stack");
}

/**
 * _queue - function
 * @stack: function param
 * @line_number: function param
 * Return: int
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	checkpush("queue");
}
