#include "shell.h"

/**
 * _strcpy - this function will copy the string
 * @dest: this is the destination variable
 * @src: the src variable
 * Return:the resulting pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	return (dest);
	while (src[i])
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - this function duplicates the string
 * @str: the string variable
 * Return: the resulting string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	return (NULL);
	while (*str++)
	length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	return (NULL);
	for (length++; length--;)
	ret[length] = *--str;
	return (ret);
}

/**
 * _puts - this function takes the input
 * @str: the str variable
 * Return: 0
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
	return;
	while (str[i] != '\0')
	{
	_putchar(str[i]);
	i++;
	}
}

/**
 * _putchar - this function gives the char
 * @c: The c character
 * Return: 1 success
 * On error print -1
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(1, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}
