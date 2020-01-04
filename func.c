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
		char words[1024];
		char count
		int i;
		while ((letter = fgetc(file)) != EOF)
		{
	//		while (letter != 32)
	//		{
				for (i = 0; letter != 104; i++)
				{
  					words[i]=letter;

//  			words[i]= '\0';
//			printf("%s", words);
				}
//			}
			words[i] = '\0';
			printf("%s", words);
			fclose(file);
		}
	}
}


/**
void allowed_opcodes(char *namefile, stack_t **headstack)
{
	char allowedopcodes[7] = ["push", "pall", "pint", "pop", "swap", "add", "nop"]
}
*/
//stack_t *add_node( **head, const int n)
//{
//}
