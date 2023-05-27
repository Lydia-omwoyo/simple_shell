#include "shell.h"

/**
 * _memset - this function fills the memory with desired conten
 * @s: the s variable
 * @b: theb variable
 * @n: the n variable
 * Return: s for success
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	s[i] = b;
	return (s);
}

/**
 * ffree - releases the string
 * @pp: the pp variable
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
	return;
	while (*pp)
	free(*pp++);
	free(a);
}

/**
 * _realloc - this function realocates the variable
 * @ptr: the pointer variable
 * @old_size: the old size variable
 * @new_size: the new size variable
 * Return: bring back the pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	return (malloc(new_size));
	if (!new_size)
	return (free(ptr), NULL);
	if (new_size == old_size)
	return (ptr);

	p = malloc(new_size);
	if (!p)
	return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
