#include "monty.h"

/**
 * push_front - function
 * @head: function param
 * @n: function param
 * Return: int
 */
stack_t *push_front(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (head == NULL || new == NULL)
		return (NULL);

	new->n = (int)n;
	new->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new;

	new->next = *head;

	*head = new;
	return (new);
}

/**
 * push_back - function
 * @head: function param
 * @n: function param
 * Return: int
 */
stack_t *push_back(stack_t **head, const int n)
{

	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp = NULL;

	if (new == NULL)
		return (NULL);

	temp = *head;
	while (temp && temp->next)
	{
		temp = temp->next;
	}

	new->n = (int)n;
	new->prev = temp;
	new->next = NULL;

	if (temp == NULL)
		*head = new;
	else
		temp->next = new;

	return (new);
}

/**
 * pop_front - function
 * @head: function param
 * Return: int
 */
int *pop_front(stack_t **head)
{
	int *num = NULL;
	stack_t *temp = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);

	num = &(*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (num);
}

/**
 * clear_stack - function
 * @head: function param
 * Return: int
 */
void clear_stack(stack_t **head)
{
	stack_t *temp = *head;

	while (temp)
	{
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
}
