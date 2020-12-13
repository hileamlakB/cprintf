#include "../printflib.h"


char *is_id(char *string)
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
			id_s[0] = ids[i];
			return (id_s);
		}
		i++;
	}
	free(id_s);
	return (NULL);
}

char *is_flag(char *string)
{

	char flags[] = {' ', '0', '#', '-', '+', '\0'};
	int i = 0;
	char *flag_s = smalloc(2);

	flag_s[1] = '\0';
	while (flags[i])
	{
		if (flags[i] == string[0])
		{
			flag_s[0] = flags[i];
			return (flag_s);
		}
		i++;
	}
	free(flag_s);
	return (NULL);
}

char *is_mod(char *format)
{
	char *mod = smalloc(3 * sizeof(char));
	char mods[] = {'l', 'h', 'j', 'z', 't', 'L', '\0'};
	int i = 0;

	mod[0] = format[0], mod[1] = format[1], mod[2] = '\0';
	if (!_strcmp(mod, "ll") || !_strcmp(mod, "hh"))
		return (mod);
	while (mods[i])
	{
		if (mod[0] == mods[i])
		{
			mod[1] = '\0';
			return (mod);
		}
		i++;
	}
	free(mod);
	return (NULL);
}

char *is_num(char *string)
{
	char *num_s = smalloc(2);

	num_s[1] = '\0';
	if (string[0] <= '9' && string[0] >= '0')
	{
		num_s[0] = string[0];
		return (num_s);
	}
	free(num_s);
	return (NULL);
}
