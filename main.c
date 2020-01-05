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
    unsigned int line_number;
    void (*f)(stack_t, unsigned int);

    headstack = NULL;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        error_fun(&headstack);
    }
    openfile(argv[1], &headstack);
    f = get_func(argv[0]);

    printf("%d\n", f(headstack, line_number));

    return (0);
}


