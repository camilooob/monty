#include "monty.h"
global_t global;
/**
 * _memcpy - prints buffer in hexa
 * @dest: output
 * @src: source
 * @n: integer
 * Return: Nothing.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;
i = 0;
	while (i < n)
{
	dest[i] = src[i];
	i++;
}
return (dest);
}
void reverseString(char* str) 
{ 
    int l, i; 
    char *begin_ptr, *end_ptr, ch; 
  
    // Get the length of the string 
    l = strlen(str); 
  
    // Set the begin_ptr and end_ptr 
    // initially to start of string 
    begin_ptr = str; 
    end_ptr = str; 
  
    // Move the end_ptr to the last character 
    for (i = 0; i < l - 1; i++) 
        end_ptr++; 
  
    // Swap the char from start and end 
    // index using begin_ptr and end_ptr 
    for (i = 0; i < l / 2; i++) { 
  
        // swap character 
        ch = *end_ptr; 
        *end_ptr = *begin_ptr; 
        *begin_ptr = ch; 
  
        // update pointers positions 
        begin_ptr++; 
        end_ptr--; 
    } 
} 
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
    char *buff = NULL, *hold = NULL, *reversed = NULL, *num_cutted = NULL;
	FILE *file = fopen(namefile, "r");
    size_t buff_long = 0;
    ssize_t line_long;
    int init_size = 0;
	void (*ffok)(unsigned int, unsigned int);
	int line_count = 0;
	ssize_t line_size;
    char delim[] = " \t\r\n";
    char str[1024];
    char *ptr = strtok(str, delim);
    int letter;
    int i = 0;

	if (file == 0)
	{
		printf("Can't open file %s\n", namefile );
		error_fun(headstack);
	}
	else
	{
        global.file = file;
        global_var();
        line_long = getline(&buff,&buff_long, global.file);

  while (line_size >= 0)
  {

    line_count++;
//	hold = buff;
	hold = malloc(sizeof *buff);

  	memcpy(hold, buff, sizeof(buff)); 
//	hold = buff;
	ptr = strtok(buff, delim);
	reverseString(hold);
	global.num = strtok(hold, delim);
 	get_func(ptr);

//	printf("%s", str);
    line_size = getline(&buff, &buff_long, global.file);
  }
  free(buff);
  buff = NULL;
  fclose(global.file);
}
}
int get_func(char *opcode)
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

int i; 
i = 0;
for (i = 0; fun[i].opcode && opcode; i++)
{
    if((strcmp(fun[i].opcode, opcode) == 0))
    {
      fun[i].f(&global.headstack, global.line_number);
      return (0);
    }
}
}


stack_t *add_node(int **head, const int n)
{
printf("soy addnode");
}
void _push(stack_t **stack, unsigned int line_number)
{
    printf("[#] Function push ");
    printf("%s\n", global.num);
}

void _pall(stack_t **stack, unsigned int line_number)
{
    printf("soy pall\n");
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
