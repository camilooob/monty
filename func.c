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
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(cmd->op, funcs[i].opcode) == 0)
		{
			funcs[i].f(cmd);
			return;
		}
		i++;
	}

	printf("L%d: unknown instruction %s\n", cmd->line_number, cmd->op);
	error_fun(command);
}
stack_t *add_node(int **head, const int n)
{
printf("soy addnode");
}

void push(command_t *command)
{
    printf("soy push");
}
void pall(command_t *command)
{
    printf("soy pall");
}
void pint(command_t *command)
{
    printf("soy pint");
}
void pop(command_t *command)
{
    printf("soy pop");
}
void swap(command_t *command)
{
    printf("soy swap");
}

void add(command_t *command)
{
    printf("soy add");
}
void nop(command_t *command)
{
    printf("soy nop");
}
void sub(command_t *command)
{
    printf("soy sub");
}
void divi(command_t *command)
{
    printf("soy div");
}
void mul(command_t *command)
{
    printf("soy mul");
}
void mod(command_t *command)
{
    printf("soy mod");
}
void pchar(command_t *command)
{
    printf("soy pchar");
}
void pstr(command_t *command)
{
    printf("soy pstr");
}
void rotr(command_t *command)
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
