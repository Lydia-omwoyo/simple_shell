#include "shell.h"

/**
 * _strlen - Gives the length of a string.
 * @r: the string to check for length.
 *
 * Return:length of string in interger.
 */
int _strlen(char *r)
{
	int j = 0;

	if (!r)
		return (0);

	while (*r++)
		j++;
	return (j);
}

/**
 * _strcmp - Does lexicogarphic comparison of two strangs.
 * @r1: first string
 * @r2: Second string
 *
 * Return: negative if r1 < r2, positive if r1 > r2, zero if r1 == r2
 */
int _strcmp(char *r1, char *r2)
{
	while (*r1 && *r2)
	{
		if (*r1 != *r2)
			return (*r1 - *r2);
		r1++;
		r2++;
	}
	if (*r1 == *r2)
		return (0);
	else
		return (*r1 < *r2 ? -1 : 1);
}

/**
 * start_w - Checks if a needle starts with Haystac.k
 * @haystack:String to be searched.
 * @needle: the substring to be found
 *
 * Return: Address of next char of haystack or NULL
 */
char *start_w(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Concatenates two Strings
 * @dest: Destination buffer
 * @src: Source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
