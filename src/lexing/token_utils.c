#include "../printflib.h"


void update_token(printing_format *node, char *var, char value, int col)
{
	char *values = smalloc(2);
	values[1] = '\0';
	values[0] = value;

	if (!_strcmp(var,  "MOD"))
		_strcat(node->mod, values);
	else if (!_strcmp(var,  "FLAG"))
		node->flag = value;
	else if (!_strcmp(var,  "WIDTH"))
		node->width = node->width * 10 + (int)value - 48;
	else if (!_strcmp(var, "PRECISION"))
		node->precision = node->precision * 10 + (int)value - 48;
	else if (!_strcmp(var,  "REPLACED"))
		node->replaced = (int)value - 48;
	else if (!_strcmp(var,  "ID"))
		node->id = value;
	node->word.col = col;
	_strcat(node->word.tok, values);
	free(values);
}
