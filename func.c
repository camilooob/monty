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
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}
//stack_t *add_node( **head, const int n)
//{
//}
