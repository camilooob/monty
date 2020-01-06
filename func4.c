#include "monty.h"
global_t global;

/**
 * get_func - opcode
 * @op: output
 * Return: Nothing.
 */
void get_func(char *op)
{
	instruction_t fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}

	};

	int i;

	for (i = 0; fun[i].opcode; i++)
	{
		if ((strcmp(fun[i].opcode, op) == 0))
		{
			fun[i].f(global.headstack, global.line_number);
			return;
		}
	}
	fprintf(stderr, "Unknown instruction\n");
	exit(EXIT_FAILURE);
}
