#include "shell.h"

/**
 * hsh - this introduces the variables
 * @info: contains the main arguments
 * @av: the av variable
 * Return: 0 for success and 1 for otherwise
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
	clear_info(info);
	if (interactive(info))
	_puts("$ ");
	_eputchar(BUF_FLUSH);
	r = get_input(info);
	if (r != -1)
	{
	set_info(info, av);
	builtin_ret = find_builtin(info);
	if (builtin_ret == -1)
	find_cmd(info);
	}
	else if (interactive(info))
	_putchar('\n');
	free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
	exit(info->status);
	if (builtin_ret == -2)
	{
	if (info->err_num == -1)
	exit(info->status);
	exit(info->err_num);
	}
	return (0);
}

/**
 * find_cmd - this function finds the cmd path
 * @info: the argument info
 * Return: 0
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
	info->line_count++;
	info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
	if (!is_delim(info->arg[i], " \t\n"))
	k++;
	if (!k)
	return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
	info->path = path;
	fork_cmd(info);
	}
	else
	{
	if ((interactive(info) || _getenv(info, "PATH=")
	|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
	fork_cmd(info);
	else if (*(info->arg) != '\n')
	{
	info->status = 127;
	print_error(info, "not found\n");
	}
	}
}

/**
 * fork_cmd - this forks the function cmd
 * @info: contains the info argument
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
	/* TODO: the error funct */
	perror("Error:");
	return;
	}
	if (child_pid == 0)
	{
	if (execve(info->path, info->argv, get_environ(info)) == -1)
	{
	free_info(info, 1);
	if (errno == EACCES)
	exit(126);
	exit(1);
	}
	/* TODO: Puts the errors */
	}
	else
	{
	wait(&(info->status));
	if (WIFEXITED(info->status))
	{
	info->status = WEXITSTATUS(info->status);
	if (info->status == 126)
	print_error(info, "Permission denied\n");
	}
	}
}
