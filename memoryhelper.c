#include "monty.h"

/**
 * freeargs - function
 * @arr: function param
 * Return: int
 */
void freeargs(char ***arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	for (i = 0; (*arr)[i] != NULL; i++)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
	}
	free(*arr);
	*arr = NULL;
}

/**
 * checkpush - function
 * @cmd: function param
 * Return: int
 */
int checkpush(char *cmd)
{
	static int num = 1;

	if (cmd != NULL && strcmp(cmd, "stack") == 0)
		num = 1;
	else if (cmd != NULL && strcmp(cmd, "queue") == 0)
		num = 0;
	return (num);
}
