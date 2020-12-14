#include "../printflib.h"

typedef struct formater_func
{
	char id;
	char *(*formater)(va_list, printing_format *);
}formater_func;



/**
 *get_printer - returns the correct pointer
 *to function based on a specifier character
 *@id: a delimeter
 *Return: a function pointer,
 *
 */
char *(*get_formater(char id))(va_list, printing_format *)
{

	formater_func funcs_list[] = {
		{'c', format_char},
		{'s', format_str},
		{'d', format_int},
		{'i', format_int},
		{'u', format_uint},
		{'b', format_bin},
		{'o', format_oct},
		{'x', format_hex},
		{'X', format_Hex},
		{'p', format_adress},
		{'r', format_rts},
		{'R', format_rot13},
		{'S', format_S},

	};
	int i = 0;
	int numofids = 13;

	while (i < numofids)
	{
		if (funcs_list[i].id == id)
			return (funcs_list[i].formater);
		i++;
	}

	return (NULL);
}
