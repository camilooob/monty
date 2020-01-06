#include "monty.h"
global_t global;

/**
 * global_var - handle function for monty languege
 * @void: num of inputs int
 * Return: None
 */
void global_var(void)
{
	global.num = NULL;
	global.headstack = NULL;
	global.line_number = 0;
	global.gbuff = NULL;

}

/**
 * main - handle function for monty languege
 * @argc: num of inputs int
 * @argv: code files char
 * Return: None
 */
int main(int argc, char **argv)
{

	stack_t *headstack;
	char reversed[10] = "push 1";

	headstack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		error_fun(&headstack);
	}
	global_var();

	openfile(argv[1], &headstack);
	reverseString(reversed);


	return (0);
}



