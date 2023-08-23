#include "monty.h"

/**
 * checkNumber - function
 * @str: function param
 * @num: function param
 * Return: int
 */
int checkNumber(char *str, int *num)
{
	size_t i;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
	}
	*num = atoi((const char *)str);
	return (0);
}

/**
 * fileLinesToArray - function
 * @filePath: function param
 * @lines: function param
 * Return: int
 */
int fileLinesToArray(char *filePath, char ***lines)
{
	int linesNum = 0, i = 0;
	char *line = NULL;
	size_t len = 1024;
	ssize_t read = 0;
	FILE *file = NULL;

	file = fopen(filePath, "r");
	*lines = NULL;
	if (file == NULL)
		return (-1);

	while (getline(&line, &len, file) != -1)
	{
		linesNum++;
		free(line);
		line = NULL;
	}
	fclose(file);
	file = NULL;

	(*lines) = malloc(sizeof(char *) * (linesNum + 1));
	file = fopen(filePath, "r");

	while ((read = getline(&line, &len, file)) != -1)
	{
		line[read - 1] = '\0';
		_remove_whitespaces(&line);
		/* printf("op: %s and len: %lu\n", line, strlen(line));*/
		(*lines)[i] = strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
	(*lines)[i] = NULL;
	fclose(file);
	file = NULL;

	return (0);
}

/**
 * _remove_whitespaces - function
 * @str: function arg
 */
void _remove_whitespaces(char **str)
{
	char *newstr = NULL;
	int oldsize = 0, spcs = 0, newsize = 0, start = 0, end = 0, i = 0, j = 0;

	if (str == NULL || *str == NULL)
		return;
	oldsize = strlen(*str), end = oldsize;
	for (i = 0; (*str)[i] != '\0'; i++)
	{
		if ((*str)[i] == '\t')
			(*str)[i] = ' ';

		if ((*str)[i] != ' ')
		{
			start = (int)i;
			break;
		}
		spcs++;
	}
	for (i = oldsize - 1; i >= 0; i--)
	{
		if ((*str)[i] != ' ')
		{
			end = (int)i;
			break;
		}
		spcs++;
	}
	end++;
	newsize = (int)oldsize - spcs;
	if (newsize == -oldsize)
		newstr = malloc(1);
	else
		newstr = malloc(newsize + 1);
	for (i = start, j = 0; i < end && end <= oldsize; i++, j++)
	{
		newstr[j] = (*str)[i];
	}
	newstr[j] = '\0';
	free(*str);
	*str = newstr;
}

/**
 * myerror - function
 * @error: function param
 * Return: int
 */
int myerror(const int *error)
{
	static int storedError;

	if (error != NULL)
		storedError = *error;
	return (storedError);
}
