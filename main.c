#include "monty.h"
global_t global;

void global_var(void)
{
	global.num = NULL;
    global.headstack = NULL;
    global.line_number = 0;

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
    unsigned int line_number;
    void (*f)(stack_t, unsigned int);
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
//	printf("%s", reversed);


    return (0);
}



