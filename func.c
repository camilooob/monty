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
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	    }
        fclose(file);
    }
	    
	
}
void get_func(command_t *command)
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
		{"div", _divi},
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
void _push(command_t *command)
{
    printf("soy push");
}
void _pall(command_t *command)
{
    printf("soy pall");
}
void _pint(command_t *command)
{
    printf("soy pint");
}
void _pop(command_t *command)
{
    printf("soy pop");
}
void _swap(command_t *command)
{
    printf("soy swap");
}
void _add(command_t *command)
{
    printf("soy add");
}
void _nop(command_t *command)
{
    printf("soy nop");
}
void _sub(command_t *command)
{
    printf("soy sub");
}
void _divi(command_t *command)
{
    printf("soy div");
}
void _mul(command_t *command)
{
    printf("soy mul");
}
void _mod(command_t *command)
{
    printf("soy mod");
}
void _pchar(command_t *command)
{
    printf("soy pchar");
}
void _pstr(command_t *command)
{
    printf("soy pstr");
}
void _rotl(command_t *command)
{
    printf("soy rotl");
}
void _rotr(command_t *command)
{
    printf("soy rotr");
}
void _stack(command_t *command)
{
    printf("soy stack");
}
void _queue(command_t *command)
{
    printf("soy queue");
}
