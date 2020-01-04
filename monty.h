#ifndef MORTY
#define MORTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

extern int sq_flag;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct command_s - command struct
 * @op: name of operation
 * @arg: argument function
 * @mode: stack or queue
 * @line_number: number of line being
 * @head: head of linked list
 * @tail: tail of linked list
 */
typedef struct command_s
{
	char *op;
	int arg;
	int *mode;
	unsigned int line_number;
	stack_t **head;
	stack_t **tail;
} command_t;
int main(int argc, char **argv);
void error_fun(stack_t **headstack);
void free_list(stack_t *head);
void get_func(command_t *command);
void openfile(char *file, stack_t **headstack);
#endif
