#include "shell.h"

/**
 * _myenv - this function prints the environment
 * @info: info variable
 *
 * Return:0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - acquires the environment value
 * @info: Carries important info
 * @name: the variable name
 * Return: 0 or 1
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
	p = starts_with(node->str, name);
	if (p && *p)
	return (p);
	node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Denotes the environment
 * @info: The info variable
 *
 *  Return: 0 or 1
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
	_eputs("Incorrect number of arguements\n");
	return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	return (0);
	return (1);
}

/**
 * _myunsetenv - Main funtion of the code
 * @info: Contains information on the arguments
 *
 * Return: 0 success
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
	_eputs("Too few arguements.\n");
	return (1);
	}
	for (i = 1; i <= info->argc; i++)
	_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - This function creates a list
 * @info: Contains information on the arguments
 * function
 * Return: 0 for Success
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
	add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
