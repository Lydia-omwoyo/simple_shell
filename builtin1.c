#include "shell.h"

/**
 * _myhistory - shows the history files from the least
 * using numbers begining with 0
 * @info: This is the information used in the variable
 * function
 * Return: Success O
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets the elias
 * @info: information variable
 * @str: this is the string variable
 * Return: 0 for success and 1 for error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
	return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - this function sets the elias
 * @info: this is the infor variable
 * @str: this is the string variable
 * Return: Success for 1 and error for 0
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
	return (1);
	if (!*++p)
	return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - This function prints the alias
 * @node: the node variable
 * Return: 0 for success and 1 error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
	p = _strchr(node->str, '=');
	for (a = node->str; a <= p; a++)
	_putchar(*a);
	_putchar('\'');
	_puts(p + 1);
	_puts("'\n");
	return (0);
	}
	return (1);
}

/**
 * _myalias - This is a replica of elias
 * @info: Contains info about the function and the
 * prototype.
 *  Return: 0 for success or 1 error
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
	node = info->alias;
	while (node)
	{
	print_alias(node);
	node = node->next;
	}
	return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
	p = _strchr(info->argv[i], '=');
	if (p)
	set_alias(info, info->argv[i]);
	else
	print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
