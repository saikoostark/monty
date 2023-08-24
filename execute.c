#include "monty.h"

/**
 * execute - function
 * @stack: function param
 * @arrayOfLines: function param
 * @lineNumber: function param
 * Return: int
 */
void execute(stack_t **stack, char **arrayOfLines, int lineNumber)
{
	char *str = strdup(arrayOfLines[lineNumber - 1]);
	char *opcode = strtok(str, " ");
	instruction_t opst[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, 
		{"pop", pop}, {"swap", swap}, {"add", add}, 
		{"nop", nop}, {"sub", sub}, {"div", div}, {"mul", mul}, 
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, 
		{"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}};

	/*
	{"queue", queue},
	{"stack", stack},
	*/
	int i = 0, flag = 1, error = 0;

	for (i = 0; opst[i].opcode != NULL; i++)
	{
		if (opcode == NULL || opcode[0] == '#')
		{
			flag = 0;
			break;
		}
		else if (strcmp(opst[i].opcode, opcode) == 0)
		{
			flag = 0, opst[i].f(stack, (unsigned int)lineNumber);
			break;
		}
	}
	if (flag)
	{
		error = EXIT_FAILURE;
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
		myerror(&error);
	}
	free(str);
	str = NULL;
}
