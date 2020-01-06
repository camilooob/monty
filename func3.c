#include "monty.h"
global_t global;
/**
 * exit_op - performs exit operations (free/close)
 * Return: No Return
 */
void exit_op(void)
{
	free(global.gbuff), fclose(global.file);
	free_stack_t(global.headstack);
}
