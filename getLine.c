#include "shell.h"

/**
 * input_buf - this is the buffer input variable
 * @info: this is the info variable
 * @buf: this is the buffer variable
 * @len: this is the len variable
 * Return: the resulting bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* incase buffer is empty, fil it */
	{
	/*bfree((void **)info->cmd_buf);*/
	free(*buf);
	*buf = NULL;
	signal(SIGINT, sigintHandler);
#if USE_GETLINE
	r = getline(buf, &len_p, stdin);
#else
	r = _getline(info, buf, &len_p);
#endif
	if (r > 0)
	{
	if ((*buf)[r - 1] == '\n')
	{
	(*buf)[r - 1] = '\0'; /* newline removed */
	r--;
	}
	info->linecount_flag = 1;
	remove_comments(*buf);
	build_history_list(info, *buf, info->histcount++);
	/* if (_strchr(*buf, ';')) in case it is a command */
	{
	*len = r;
	info->cmd_buf = buf;
	}
	}
	}
	return (r);
}

/**
 * get_input - this function acquires new input
 * @info: contains argument information
 * Return: the resulting bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' buffers command */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
	return (-1);
	if (len) /* acts when there is command in the buffer */
	{
	j = i; /* opens new interator */
	p = buf + i; /* calls the pointer */

	check_chain(info, buf, &j, i, len);
	while (j < len) /* iterate it to the very end */
	{
	if (is_chain(info, buf, &j))
	break;
	j++;
	}

	i = j + 1; /* increases it ';'' */
	if (i >= len) /* moves to buffer end */
	{
	i = len = 0; /* readjusts position */
	info->cmd_buf_type = CMD_NORM;
	}

	*buf_p = p; /* used to change pointers */
	return (_strlen(p)); /* shows length */
	}

	*buf_p = buf; /* incase it is not a chain move to  _getline() */
	return (r); /* give the length from  _getline() */
}

/**
 * read_buf - checks buffer
 * @info: the info variable
 * @buf: buffer variable
 * @i: this is the size variable
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
	return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
	*i = r;
	return (r);
}

/**
 * _getline - acquires input
 * @info: contains argument info
 * @ptr: this is a pointer address
 * @length: this is the pointer size
 * Return: s success
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
	s = *length;
	if (i == len)
	i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
	return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* IN case of MALLOC FAILURE MSG */
	return (p ? free(p), -1 : -1);

	if (s)
	_strncat(new_p, buf + i, k - i);
	else
	_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
	*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler -Handles the ctrl c function
 * @sig_num: the sial number variable
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
