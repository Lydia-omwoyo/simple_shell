#include "shell.h"
#include "stdio.h"
#include "starts_with.c"

/**
 * is_cmd - examines if file is executable
 * @info: contains the argument info
 * @path: the file path
 * Return: 1 for true or 0 for otehrwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
	{
	return (1);
	}
	return (0);
}

/**
 * dup_chars - this function duplicates the character
 * @pathstr: the path string variable
 * @start: the start variable
 * @stop: the stop variable
 * Return: the resulting character
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
	if (pathstr[i] != ':')
	buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - determines the cmd path
 * @info: the info variable
 * @pathstr: this is the path string
 * @cmd: this is the cmd variable
 * Return: the cmd path
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
	return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
	if (is_cmd(info, cmd))
	return (cmd);
	}
	while (1)
	{
	if (!pathstr[i] || pathstr[i] == ':')
	{
	path = dup_chars(pathstr, curr_pos, i);
	if (!*path)
	_strcat(path, cmd);
	else
	{
	_strcat(path, "/");
	_strcat(path, cmd);
	}
	if (is_cmd(info, path))
	return (path);
	if (!pathstr[i])
	break;
	curr_pos = i;
	}
	i++;
	}
	return (NULL);
}
