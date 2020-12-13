#include "../printflib.h"

/**
 *findd - finds the number occurance of tof in str
 *@str: string to be searched
 *@tof: string to find
 *Return: the number of times the delimeter ocured
 */
int findd(char *str, char *tof)
{
	char *tokenized = NULL, *new = NULL;
	int i = 0;

	if (_strlen(tof) > _strlen(str))
		return (0);
	new = _strdup(str);
	tokenized = _strtok(new, tof, 1);
	while (tokenized != NULL)
	{
		i++;
		tokenized = _strtok(NULL, tof, 1);
	}
	free(new);
	/*icase tofind is at th end*/
	if (_strcmps(str + _strlen(str) - _strlen(tof), tof) == 1)
		i++;
	return (i - 1);
}
/**
 *fnrep - finds and replaces part of a string
 *@str: manipulated string (must be malloced)
 *      this string should also be freed by the caller
 *@torep: subset of str to be replaced
 *@repwith: string to replace torep
 *Return: 0 on sucess and -1 on faliure
 */
int fnrep(char **str, char *torep, char *repwith)
{
	char *tokenized = NULL, *tmp, *new = smalloc(1);
	int rep = 0, tor = findd(*str, torep), newlen = 0;

	tokenized = _strtok(*str, torep, 1);
	*new = '\0';
	while (tokenized != NULL)
	{
		newlen = _strlen(new) + _strlen(tokenized) + _strlen(repwith);
		tmp = srealloc(new, newlen +  2);
		new = tmp;
		_strcat(new, tokenized);
		if (rep < tor)
			_strcat(new, repwith);
		rep++, tokenized = _strtok(NULL, torep, 1);
	}
	free(*str);
	*str = new;
	return (0);
}


/**
 *_strcmpd - A special compare function that compares if one char
 * inside the sub string is equal to the first char of fstring
 *@fstring: fstring
 *@sub: subset
 *Return: 1 on success and -1 on faliur
 */
int _strcmpd(char *fstring, char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (!*fstring)
		return (-1);
	if (_strlen(fstring) < _strlen(sub))
		return (-1);
	while (*sub)
	{
		if (*sub == *fstring)
			return (1);
		sub++;
	}
	return (-1);
}
/**
 *_strcmps - A special compare function that compares if part of a string
 * inside the sub char is equal to the second string
 *@fstring: fstring
 *@sub: subset
 *Return: 1 on success and -1 on failuer
 */
int _strcmps(char *fstring, char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (!*fstring)
		return (-1);
	if (_strlen(fstring) < _strlen(sub))
		return (-1);
	while (*sub && *fstring)
	{
		if (*sub != *fstring)
			return (-1);
		sub++, fstring++;
	}
	return (1);
}

/**
 * _strtok - tokenizes a string according to a certain delimiter
 * it doesnt creat a new string to hold the tokens but rather creats a
 * a static variable that will directly copy str and puts the null
 * terminator everytime it finds the delimeter, the default str will be
 * manipulated so beware
 * for example if you have a string str = "helo; now; bo"
 * when _strtok is called for the first time (_strtok(str, ";")) it will put
 * \0 (a null terminator in the first location of the delimeter so the str
 * variable will be "helo\0 nowo; bo", ";" and it will be returned and the
 * static variable save would hold " nowo; bo" and when _strtok is called
 * for the second time _strtok(NULL, ";"); the same cyle continue
 * but this time instead of str save will be manipulated. This
 *cycle continues untile save == NULL
 * @str: the string to be tokenized
 * @delimeter: the delimiter to separate tokens
 * @whichf: which comparign funcion to use, 0 for strcmpd, and 1 for strcmps
 * Return: a character pointer to the current delimited token
 */
char *_strtok(char *str, char *delimeter, int whichf)
{
	static char *save;
	char *_new = NULL;
	int i = 0, (*func)(char *, char *), loc;

	func = (whichf == 0) ? _strcmpd : _strcmps;
	loc = (whichf) ? _strlen(delimeter) - 1 : 0;
	if (!str || !*str)
	{
		if (!save || !*save)
			return (NULL);

		while (func(save + i, delimeter) != 1 && *(save + i) != '\0')
			i++;
		if (*(save + i) == '\0')
		{
			_new = save, save = NULL;
			return (_new);
		}
		_new = save;
		*(save + i) = '\0';
		save = save + i + loc + 1;

		return (_new);

	}
	while (func(str + i, delimeter) != 1 && *(str + i) != '\0')
		i++;

	if (*(str + i) == '\0')
	{
		save = NULL;
		return (str);
	}
	save = str + i + loc + 1;
	*(str + i) = '\0';
	return (str);
}
