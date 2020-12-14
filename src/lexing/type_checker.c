#include "../printflib.h"


int is_id(char *string)
{
	char ids[] = {'d','i','u','o','x','X','f','F','e','E','g','G',
		'a','A','c','s','p','n','%', 'b', 'R', 'r', 'S', '\0'};
	int i = 0;
	char *id_s = smalloc(2);

	id_s[1] = '\0';
	while (ids[i])
	{
		if (ids[i] == string[0])
		{
			free(id_s);
			return (1);
		}
		i++;
	}
	free(id_s);
	return (0);
}

int is_flag(char *string)
{

	char flags[] = {' ', '0', '#', '-', '+', '\0'};
	int i = 0;
	char *flag_s = smalloc(2);

	flag_s[1] = '\0';
	while (flags[i])
	{
		if (flags[i] == string[0])
		{
			free(flag_s);
			return (1);
		}
		i++;
	}
	free(flag_s);
	return (0);
}

int is_mod(char *format)
{
	char *mod = smalloc(3 * sizeof(char));
	char mods[] = {'l', 'h', 'j', 'z', 't', 'L', '\0'};
	int i = 0;

	mod[0] = format[0], mod[1] = format[1], mod[2] = '\0';
	if (!_strcmp(mod, "ll") || !_strcmp(mod, "hh"))
	{
		free(mod);
		return (2);
	}
	while (mods[i])
	{
		if (mod[0] == mods[i])
		{
			free(mod);
			return (1);
		}
		i++;
	}
	free(mod);
	return (0);
}

int is_num(char *string)
{

	if (string[0] <= '9' && string[0] >= '0')
		return (1);
	return (0);
}

bool is_valid(printing_format *head)
{

	char *str = head->word.tok;

	if (!head)
		return (false);

	/*flag, width and precision are optional*/
	/*on the case of precision should be handled incase
	a . is used but no precision*/

	if (!head->precision)
		while (*str)
		{
			if (*str == '.')
			{
				head->validity = false;
				return (false);
			}
			str++;
		}

	if (!is_id(&(head->id)))
		{
		head->validity = false;
		return (false);
	}
	head->validity = true;
	return (true);
}


