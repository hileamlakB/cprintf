#include "../printflib.h"

typedef struct formater_func
{
	char id;
	char *()(va_list, priting_format *);
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
		{'u', format_unsigned},
		{'b', format_binary},
		{'o', format_octal},
		{'x', format_hexa},
		{'X', format_hexa},
		{'p', format_address},
		{'r', format_reverse},
		{'R', format_rot13},
		{'S', format_},

		}

	return (printer);
}
