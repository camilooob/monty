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
/**
 * reverseString - prints buffer in hexa
 * @str: output
 * Return: Nothing.
 */
void reverseString(char *str)
{
	int l, i;
	char *begin_ptr, *end_ptr, ch;

	l = strlen(str);

	begin_ptr = str;
	end_ptr = str;

	for (i = 0; i < l - 1; i++)
		end_ptr++;

	for (i = 0; i < l / 2; i++)
	{
		ch = *end_ptr;
		*end_ptr = *begin_ptr;
		*begin_ptr = ch;

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

/**
 * openfile - read fun
 * @namefile: output
 * @headstack: num
 * Return: Nothing.
 */
void openfile(char *namefile, stack_t **headstack)
{
	char *buff = NULL, *hold = NULL;
	FILE *file = fopen(namefile, "r");
	size_t buff_long = 0;
	ssize_t line_long;
	int line_count = 0;
	ssize_t line_size;
	char delim[] = " \t\r\n";
	char str[1024];
	char *ptr = strtok(str, delim);
	(void)line_long;
	if (file == 0)
	{
		printf("Can't open file %s\n", namefile);
		error_fun(headstack);
	}
	else
	{
		global.file = file;
		global_var();
		line_long = getline(&buff, &buff_long, global.file);
		while (line_size >= 0)
		{
			line_count++;
			hold = malloc(sizeof(*buff));
			memcpy(hold, buff, (sizeof(buff)));
			ptr = strtok(buff, delim);
			reverseString(hold);
			global.num = strtok(hold, delim);
			get_func(ptr);
			line_size = getline(&buff, &buff_long, global.file);
		}
		free(buff);
		buff = NULL;
		fclose(global.file);
	}
}
/**
 * get_func - opcode
 * @opcode: output
 * Return: Nothing.
 */
int get_func(char *opcode)
{
	instruction_t fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}

	};

	int i;

	i = 0;
	for (i = 0; fun[i].opcode && opcode; i++)
	{
		if ((strcmp(fun[i].opcode, opcode) == 0))
		{
			fun[i].f(&global.headstack, global.line_number);
			return (0);
		}
	}
	return (0);
}

/**
 * _push - read fun
 * @stack: output
 * @line_number: num
 * Return: Nothing.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!_isnumber(global.num))
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(global.num);
	add_dnodeint(stack, n);
}

/**
 * _pall - read fun
 * @stack: output
 * @line_number: num
 * Return: Nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (stack && tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - read fun
 * @stack: output
 * @line_number: num
 * Return: Nothing.
 */
void _pint(stack_t __attribute__((__unused__)) **stack, unsigned int __attribute__((__unused__)) line_number)
{
	
}
