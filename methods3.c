#include "monty.h"

/**
 * mod - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    int error = 0;
    int a = 0;

    (void)line_number;

    if (temp == NULL || temp->next == NULL)
    {
        error = EXIT_FAILURE;
        myerror(&error);
        fprintf(stderr, "L%u: usage:  can't mod, stack too short\n", line_number);
        return;
    }

    if (temp->n == 0)
    {
        error = EXIT_FAILURE;
        myerror(&error);
        fprintf(stderr, "L%u: division by zero\n", line_number);
        return;
    }

    a = temp->next->n % temp->n;
    pop_front(stack);
    pop_front(stack);
    push_front(stack, a);
}

/**
 * pchar - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *h;
    int error = 0;

    h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		error = EXIT_FAILURE;
        myerror(&error);
        return;
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		error = EXIT_FAILURE;
        myerror(&error);
        return;
	}
	printf("%c\n", h->n);
}

/**
 * pstr - function
 * @stack: function param
 * @line_number: function param
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *h;
	(void)line_number;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}