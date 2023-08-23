#include "monty.h"

/**
 * main - main function
 * @argc: function param
 * @argv: function param
 * Return: int
 */
int main(int argc, char const *argv[])
{
	int i = 0;
	stack_t *head = NULL;
	char **arrayOfLines = NULL;
	int error = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	if (fileLinesToArray((char *)argv[1], &arrayOfLines) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	myerror(&error);
	for (i = 0; arrayOfLines[i] != NULL; i++)
	{
		execute(&head, arrayOfLines, i + 1);
		if (myerror(NULL) != 0)
			break;
	}

	clear_stack(&head);
	freeargs(&arrayOfLines);
	return (myerror(NULL));
}
