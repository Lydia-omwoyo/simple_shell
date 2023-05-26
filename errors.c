#include "shell.h"

/**
 * _eputs - this is the input
 * @str: this is the string variable
 * Return: 0
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
	return;
	while (str[i] != '\0')
	{
	_eputchar(str[i]);
	i++;
	}
}

/**
 * _eputchar - prints the c character
 * @c: This is the c variable
 * Return: 1 for success
 * On error print 0
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(2, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}

/**
 * _putfd - prints on fd
 * @c: This is the c variable
 * @fd: This is the fd variable
 * Return: 1 for success 0 for errror
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(fd, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}

/**
 * _putsfd - main part of the code
 * @str: this is the string variable
 * @fd: the fd variable
 * Return: the resulting value
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
	return (0);
	while (*str)
	{
	i += _putfd(*str++, fd);
	}
	return (i);
}
