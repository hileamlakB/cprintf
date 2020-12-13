#include "../printflib.h"

/*
 ******Author
 * Hileamlak M. Yitayew
 * hilea.buisness@gmail.com
 */

/**
 *sarrdup - safe array duplicate
 *@src: array to be duplicated
 *Return: a double pointer to the newly allocated array
 */
char **sarrdup(char **src)
{
	char **tmp = smalloc(sizeof(char *) * (arlen(src) + 2));
	char **_tmp = tmp;

	while (*src)
		*_tmp = _strdup(*src), _tmp++, src++;
	*_tmp = NULL;
	return (tmp);

}

/**
 *freedp - frees a double pointer that has been correctly allocated
 *	It is the programers duty to send a valid double pointer
 *@a: double pointer to be freed
 */
void freedp(char **a)
{
	char **_a = a;

	if (!a)
		return;
	while (*_a)
	{
		free(*_a);
		_a++;
	}
	free(a);
}

/**
 *arlen - returns the lenght of a string array
 *@a: pointer to the first string
 *Return: lenght of the array
 */
int arlen(char **a)
{
	int i = 0;

	if (!a)
		return (i);
	while (*a)
		i++, a++;
	return (i);
}
/**
 *trims - trims space in front of a string and more than one spaces in between
 *@str: pointer to the string to be edited
 *@strt: string to be trimed
 */
void trims(char **str, char *strt)
{
	char *new = smalloc(sizeof(char) * 1), *_str = strt, *tmp;
	int first = 1, count = 1, index = 0;

	*new = '\0';
	while (*_str)
	{
		if (*_str == ' ' && first)
			_str++;
		else if (*_str == ' ' && count)
			count++, _str++;
		else if (*_str != ' ')
		{
			tmp = smalloc(sizeof(char) * (_strlen(new) + 3));
			if (!tmp)
				exit(-1);
			_strcpy(tmp, new);
			if (count > 1)
				tmp[index] = ' ', index++;

			tmp[index] = *_str;
			tmp[index + 1] = '\0';
			free(new);
			first = 0, count = 1, new = tmp, index++, _str++;
		}
	}
	*str = new;
}
