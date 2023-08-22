#include "monty.h"

/**
 * freeargs - function
 * @arr: function param
 * Return: int
 */
void freeargs(char ***arr)
{
	int i = 0;

	for (i = 0; (*arr)[i] != NULL; i++)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
	}
	free(*arr);
	*arr = NULL;
}
