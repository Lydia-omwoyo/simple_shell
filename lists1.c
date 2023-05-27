#include "shell.h"

/**
 * list_len - this function lists the length
 * @h: the h variable
 * Return: list size
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
	h = h->next;
	i++;
	}
	return (i);
}

/**
 * list_to_strings - populates the string list
 * @head: the head pointer
 * Return: string array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
	return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
	return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
	str = malloc(_strlen(node->str) + 1);
	if (!str)
	{
	for (j = 0; j < i; j++)
	free(strs[j]);
	free(strs);
	return (NULL);
	}

	str = _strcpy(str, node->str);
	strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints the list
 * @h: points to the h variable
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
	_puts(convert_number(h->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	h = h->next;
	i++;
	}
	return (i);
}

/**
 * node_starts_with - gives the node that comemnces with a prefix
 * @node: this is the node pointer
 * @prefix: the prefix variable
 * @c: the c variable
 * Return: the resulting node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
	p = starts_with(node->str, prefix);
	if (p && ((c == -1) || (*p == c)))
	return (node);
	node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gives the node index
 * @head: points to the head variable
 * @node: points to the node
 * Return: the index value
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
	if (head == node)
	return (i);
	head = head->next;
	i++;
	}
	return (-1);
}
