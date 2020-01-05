#include "monty.h"
/**
 * * error_fun - exit and free stack
 * @headstack: head stack pointer
 *
 */
void error_fun(stack_t **headstack)
{
    if (*headstack)
        free_list(*headstack);
    exit(EXIT_FAILURE);
}
/**
 * free_list - free memory of the linked list
 * @head: first node of linked list
 *
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void openfile(char *namefile, stack_t **headstack)
{
	FILE *file = fopen(namefile, "r");


	if (file == 0)
	{
		printf("Can't open file %s\n", namefile );
		error_fun(headstack);
	}
	else
	{
		int letter;
        char str[1024];
        int i = 0;
		while ((letter = fgetc(file)) != EOF)
		{
            str[i] = letter;
            i++;
        }
        int init_size = strlen(str);
	    char delim[] = " \t\r\n";
        char *ptr = strtok(str, delim);

	    while(ptr != NULL)
	    {
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);
	    }
        fclose(file);
    }
}

void get_func(stack_t **stack, unsigned int line_number)
{
	instruction_t fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
//		{"div", _divi},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}

	};
}

stack_t *add_node(int **head, const int n)
{
printf("soy addnode");
}
void _push(stack_t **stack, unsigned int line_number)
{
    printf("soy push");
}

void _pall(stack_t **stack, unsigned int line_number)
{
    printf("soy pall");
}
void _pint(stack_t **stack, unsigned int line_number)
{
    printf("soy pint");
}
void _pop(stack_t **stack, unsigned int line_number)
{
    printf("soy pop");
}
void _swap(stack_t **stack, unsigned int line_number)
{
    printf("soy swap");
}
void _add(stack_t **stack, unsigned int line_number)
{
    printf("soy add");
}
void _nop(stack_t **stack, unsigned int line_number)
{
    printf("soy nop");
}
void _sub(stack_t **stack, unsigned int line_number)
{
    printf("soy sub");
}
void _divi(stack_t **stack, unsigned int line_number)
{
    printf("soy div");
}
void _mul(stack_t **stack, unsigned int line_number)
{
    printf("soy mul");
}
void _mod(stack_t **stack, unsigned int line_number)
{
    printf("soy mod");
}
void _pchar(stack_t **stack, unsigned int line_number)
{
    printf("soy pchar");
}
void _pstr(stack_t **stack, unsigned int line_number)
{
    printf("soy pstr");
}
void _rotl(stack_t **stack, unsigned int line_number)
{
    printf("soy rotl");
}
void _rotr(stack_t **stack, unsigned int line_number)
{
    printf("soy rotr");
}
void _stack(stack_t **stack, unsigned int line_number)
{
    printf("soy stack");
}
void _queue(stack_t **stack, unsigned int line_number)
{
    printf("soy queue");
}
