#include "monty.h"
global_t global;
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
	char *buff = NULL;
	char *ptr;
	int line_count = 0;
	size_t buff_long = 0;
	ssize_t line_long;
	ssize_t line_size;
	FILE *file = fopen(namefile, "r");
	char delim[] = " \t\r\n";
	(void)line_long;
    if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", namefile);
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		printf("Can't open file %s\n", namefile);
		exit(EXIT_FAILURE);
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
			ptr = strtok(buff, delim);
			global.num = strtok(NULL, delim);
			get_func(ptr);
			line_size = getline(&buff, &buff_long, global.file);
		}
		free(buff);
		buff = NULL;
		fclose(global.file);
	}
}
