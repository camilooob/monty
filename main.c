#include "monty.h"
int sq_flag = 0;
/**
 * main - handle function for monty languege
 * @argc: num of inputs int
 * @argv: code files char
 * Return: None
 */
int main(int argc, char **argv)
{
    stack_t *headstack;

    headstack = NULL;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        error_fun(&headstack);
    }
    openfile(argv[1], &headstack);
    free_list(headstack);
    return (0);
}


