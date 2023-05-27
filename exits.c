#include "shell.h"

/**
 **_strncpy - this funtcion is used to copy string value
 *@dest: this is the destimation variable
 *@src: the src variable
 *@n: the n variable
 *Return: 1 for success
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
	dest[i] = src[i];
	i++;
	}
	if (i < n)
	{
	j = i;
	while (j < n)
	{
	dest[j] = '\0';
	j++;
	}
	}
	return (s);
}

/**
 **_strncat - introduces the string code
 *@dest: this is the first string code
 *@src: the src variable
 *@n: the n variable
 *Return: 1 for success or 0 for errors
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	i++;
	while (src[j] != '\0' && j < n)
	{
	dest[i] = src[j];
	i++;
	j++;
	}
	if (j < n)
	dest[i] = '\0';
	return (s);
}

/**
 **_strchr - determines the string character
 *@s: the s variable
 *@c: the character variable
 *Return: 1 for success or 0 for error
 */
char *_strchr(char *s, char c)
{
	do {
	if (*s == c)
	return (s);
	} while (*s++ != '\0');

	return (NULL);
}
