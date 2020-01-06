#include "monty.h"
global_t global;

/**
 * get_func - opcode
 * @opcode: output
 * Return: Nothing.
 */
int get_func(char *opcode)
{
	instruction_t fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}

	};

	int i;

	i = 0;
	for (i = 0; fun[i].opcode && opcode; i++)
	{
		if ((strcmp(fun[i].opcode, opcode) == 0))
		{
			fun[i].f(&global.headstack, global.line_number);
			return (0);
		}
	}
	fprintf(stderr, "Unknown instruction\n");
	exit(EXIT_FAILURE);
	return (0);
}
