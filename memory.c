#include "shell.h"

/**
 * bfree - Helps to frees a pointer
 * It also nullifies the string
 * @ptr: Pointer address to be let free.
 *
 * Return: 1 if free, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

