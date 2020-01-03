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
    char *buffer = NULL;
	char *line;
	size_t i = 0;
	int count = 1;
	instruct_func s;
	int check;
	int read;
	FILE *file = fopen(namefile, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", namefile);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", count, line);
			error_exit(stack);
		}
		s(stack, count);
		count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}

stack_t *add_node( **head, const int n)
{
    stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);

	if (*head == NULL)
	{
		newnode->n = n;
		newnode->next = NULL;
		newnode->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = newnode;
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
	return (*head);
}
