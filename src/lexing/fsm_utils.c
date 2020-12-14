#include "../printflib.h"

#include <stdio.h>

/*
 *****Author
 * Hileamlak M. Yitayew
 * hilea.buisness@gmail.com
 */

/*
 *****Program description
 * In this file there are function that are capable of
 * manipulating a linked list  * called edge. this edge
 * linked list is defined inside lexer.h. The functions in
 * this file include functionalites like, appending, creating,
 * deleteing, freeing, printing finding, and replacing for
 * the edge linked list.
 */


/*
 *****Flow text
 * This function takes a varidaic list containing elements needed
 * to make n edges. It will use a loop until all the information
 * from the varidaic list has been copied to an edge and the edge
 * is attached to the linked list. Incase it couldn't creat an edge
 * it exits with a -1 status code. The varidaic list is excpected to have
 * elements in (int, char *, int, int, char *, int, ...) format where the
 * first int is the name of the edge, the char* is the label on the path
 * to the next edge, the next int is the name of the next edge.
 */

/*
 *****
 *Discliamer
 * if n is less than the length of things send in the variadic list,
 * the behaviour is undefined if elements aren't send to the variqadic
 * list in the form int, char *, int the behaviour is undefined
 * the char * in the edge and the edge it self have to be freed once used.
 */

/**
 * add_edge_fsm - adds edges to the linked list, creats the list if it
 * doesn't exist
 * @n: number of edges to creat
 * @head: a pointer the first element of the linked list
 * @...: a variadic list containing the information needed to
 * create the n edges
 *Return: a pointer to the head of the linked list
 */

edge *add_edge_fsm(unsigned int n, edge **head, ...)
{
	unsigned int i = 0;
	edge *_head = *head, *new_edge;
	va_list items;

	va_start(items, head);

	while (i < n)
	{
		new_edge = smalloc(sizeof(edge));
		new_edge->current_state = va_arg(items, int);
		new_edge->label = _strdup(va_arg(items, char *));
		new_edge->next_state = va_arg(items, int);
		new_edge->next = NULL;
		if (!_head)
		{
			*head = new_edge;
			_head = new_edge;
		}
		else
		{
			_head->next = new_edge;
			_head = new_edge;
		}
		i++;

	}

	va_end(items);
	return (*head);
}
/**
 * print_fsm - prints a finite state machine that is in
 * the form a linked list
 * @head: a pointer to the first element of the linked list
 */
void print_fsm(edge *head)
{
	edge *_head = head;

	while (_head)
	{
		/*!Change this printf function later*/
		printf("(%i, %s) -> %i\n",
				_head->current_state,
				_head->label,
				_head->next_state);
		_head = _head->next;
	}
}

/**
 *free_fsm - frees a finite state machine(a linked list)
 *@head: a pointer to the first element of the linked list
 *(finite state machine)
 */
void free_fsm(edge *head)
{
	edge *_head = head, *tmp;

	while (_head)
	{
		free(_head->label);
		tmp = _head->next;
		free(_head);
		_head = tmp;
	}
}

edge *find_edge(edge *head, int edge_name, char *label)
{

	edge *_head = head;

	while (_head)
	{
		if (_head->current_state == edge_name && !_strcmp(_head->label, label))
			return (_head);
		_head = _head->next;
	}
	return (_head);
}

printing_format *fsm_sim(int current, char *string, edge *edges, int accepting, int started, printing_format *head, char *current_mode)
{
	char *t_str = smalloc(10);
	edge *destination = smalloc(sizeof(edge));
	int mod_len = 0;

	if (current == accepting)
		return (head);
	head->replaced += 1;
	if (string[0] == ' ' && current == 0)
		return (NULL);
	if (!_strlen(string))
		return (NULL);
	/* var expansion*/

	mod_len = is_mod(string);
	if (mod_len)
		_strcpy(t_str, "MOD"), 	_strcpy(current_mode, "MOD");
	else if (is_id(string) && current != 0)
		_strcpy(t_str, "ID"), 	_strcpy(current_mode, "ID");
	else if (is_flag(string) && current == 1)
		_strcpy(t_str, "FLAG"), _strcpy(current_mode, "FLAG");
	else if (is_num(string))
	{
		_strcpy(t_str, "NUM");
		if (_strcmp(current_mode, "PRECISION"))
			_strcpy(current_mode, "WIDTH");
	}
	else
	{
		*t_str = string[0], *(t_str + 1) = '\0';
		if (string[0] == '.')
			_strcpy(current_mode, "PRECISION");
	}
	started = 0;
	destination = find_edge(edges, current, t_str);
	if (destination)
	{
		started = 1;
		current = destination->next_state;
		t_str[0] = string[0], t_str[1] = '\0';
		free(t_str);

		update_token(head, current_mode, string, mod_len);
		string += 1;
		return (fsm_sim(current, string, edges, accepting, started, head, current_mode));
	}
	else if (string[0] != '%' && string[0] !=' ' && current == 0)
	{
		_strcpy(t_str, "NOT_%");
		destination = find_edge(edges, current, t_str);
		if (started)
		{
			printf("Wrong format for printf");
			return (NULL);
		}
		if (destination)
		{
			current = destination->next_state;
			t_str[0] = string[0], t_str[1] = '\0';

			free(t_str);
			/*free(destination);*/

			if (string[0] != '.')
				update_token(head, current_mode, string, mod_len);
			string += 1;
			return (fsm_sim(current, string, edges, accepting, started, head, current_mode));
		}
	}
	free(t_str);
	/*free(destination);*/
	current = 0;
	string += 1;
	head->replaced = 0;
	update_token(head, "", "", mod_len);
	return (NULL);

}

/*
 *Example
 *fsm_util_test.c
 */
