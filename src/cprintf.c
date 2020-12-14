#include "printflib.h"
#include <stdio.h>

void clean_printing_format(printing_format *formated_str)
{
	formated_str->flag = '\0';
	formated_str->width = '\0';
	formated_str->id = '\0';
	formated_str->precision = 0;
	formated_str->zero_fill = false;
	formated_str->validity = false;
	formated_str->word.col = 0;


}
void print_printing_format(printing_format *formated_str)
{
	printf("flag=>%c\n", formated_str->flag);
	printf("width=>%i\n", formated_str->width);
	printf("mod=>%s\n", formated_str->mod);
	printf("id=>%c\n", formated_str->id);
	printf("precision=>%i\n", formated_str->precision);
	printf("zero_fill=>%u\n", formated_str->zero_fill);
	printf("validity=>%u\n", formated_str->validity);
	printf("word.tok=>%s\n", formated_str->word.tok);
	printf("word.type =>%s\n", formated_str->word.type);
	printf("word.col =>%i\n", formated_str->word.col);
	printf("=>-------------------------------------------\n\n\n");


}
/**
 * _printf - a function that prints anything using
 *           posix callex via the write function
 * @format: formated string to be printed
 * Return: the number of things printed
 */
int _printf(const char *format, ...)
{
	va_list items;
	char *t_str = NULL, *str = NULL, *str_mod = smalloc(20), *replaced = NULL;
	edge **grammer_list = prepare_lexer();
	/*make it null here and creat it in the function*/
	printing_format *formated_str = smalloc(sizeof(printing_format));
	printing_format *returned = NULL;
	/*accepting state of the different lexer grammers at index*/
	/*abstract this away in some function call*/
	int accepting[] = {7, 6, 5, 4, 6, 5, 4, 3, 6, 5, 4, 4, 5, 4, 3, 2, 1};
	int i = 0;

	/*open printer*/
	printer(NULL, 0);
	if (!format || (*format == '%' && _strlen((char *)format) == 1))
		return (-1);

	str = _strdup((char *)format);
	t_str = str;


	formated_str->word.tok = smalloc(100);

	va_start(items, format);
	while (true)
	{
		returned = NULL;

		/*clean up the format holder*/
		clean_printing_format(formated_str);
		i = 0;
		while (!returned && i < 17)
			formated_str->replaced = 0, returned = fsm_sim(0, str, grammer_list[i], accepting[i], 0, formated_str, str_mod), i += 1;

		str += formated_str->replaced;
		if (is_valid(formated_str))
		{
			formated_str-> = get_formater(formated_str->id);
			replaced = (formated_str->)(items);
			printer(replaced, 1);
		}
		else
			printer(formated_str->word.tok, 1);

		if (!str)
			break;
		if (!_strlen(str))
			break;
		_strcpy(formated_str->word.tok, "");
		_strcpy(str_mod, "");
	}

	/*Print everything in the que*/
	printer(NULL, 2);
	free(t_str);
	va_end(items);
	return (10);
}

/*parser()*/
/*{*/
/*}*/
